#include "sample.h"
#include "rbprocess.h"


Sample::Sample(Marker* m) {
	marker = m;
	length = 0;
	data = new float[0];
	olength = 0;
	odata = new float[0];
	stretchMode = 0;
	_processing = false;
	_finished = 0;
}


Sample::~Sample() {
	delete[] data;
}


int Sample::getLength() {
	return length;
}


int Sample::getGuessedLength() {
	return int(olength * marker->getLengthf());
}


float Sample::get(float nn) {
	if (_processing) {
		return 0;
	}
	int i = int(length * nn);
	if (i < 0 || i >= length) {
		return 0;
	}
	return data[i];
}


float Sample::getOld(float o) {
	int i = int((olength - 1) * o);
	if (i < 0 || i >= olength) {
		return 0;
	}
	return odata[i];
}


int Sample::getStretchMode() {
	return stretchMode;
}


void Sample::setStretchMode(int m) {
	if (!_processing) {
		stretchMode = m;
	}
}


int Sample::loadFile(const char* fileName) {
	// TODO madlib/mp3 support
	if (_processing) {
		return 1;
	}
	SNDFILE *sndfile = NULL;

	// open file
	sndfile = sf_open(fileName, SFM_READ, &sfinfo);
	if (!sndfile) {
		std::cerr << "ERROR: Failed to open input file \"" << fileName << "\": "
		<< sf_strerror(sndfile) << std::endl;
		return 1;
	}

	// setup data
	olength = sfinfo.frames;  // expected length
	delete[] odata;
	odata = new float[olength];

	// read file into data
	float ptr[10240 * sfinfo.channels];
	int count2 = 0;
	while (true) {
		int count = sf_readf_float(sndfile, ptr, 10240);
		if (count <= 0) {
			break;
		}

		// save ptr in data
		for (int i = 0; i < count * sfinfo.channels; i += sfinfo.channels) {
			odata[count2] = 0;
			for (int j = 0; j < sfinfo.channels; ++j) {
				odata[count2] += ptr[i + j];
			}
			odata[count2] /= sfinfo.channels;
			count2++;
		}
	}
	sf_close(sndfile);
	olength = count2;  // exact length

	// fill data
	return process();
}


int Sample::writeFile(const char* fileNameOut) {
	if (_processing) {
		return 1;
	}
	if (length <= 0) {
		std::cerr << "ERROR: Load a file first" << std::endl;
		return 1;
	}
	SNDFILE *sndfileOut;
	SF_INFO sfinfoOut;

	// open file
	sfinfoOut.channels = 1;
	sfinfoOut.format = sfinfo.format;
	sfinfoOut.samplerate = sfinfo.samplerate;
	sfinfoOut.sections = sfinfo.sections;
	sfinfoOut.seekable = sfinfo.seekable;

	sndfileOut = sf_open(fileNameOut, SFM_WRITE, &sfinfoOut);
	if (!sndfileOut) {
		std::cerr << "ERROR: Failed to open output file \"" << fileNameOut
		<< "\" for writing: " << sf_strerror(sndfileOut) << std::endl;
		return 1;
	}
	sf_write_float(sndfileOut, data, length);
	sf_close(sndfileOut);
	return 0;
}


int Sample::process() {
	// process_bg();
	if (_processing) {
		return 1;
	}
	setFinished(0);
	pthread_t thread;
	pthread_create(&thread, NULL, Sample::EntryPoint, (void*)this);
	// process_bg();
	return 0;
}


void* Sample::EntryPoint(void* pthis)
{
	Sample* pt = (Sample*)pthis;
	int error = pt->process_bg();
	pthread_exit((void*)error);
}


int Sample::process_bg() {
	/*
	 * This function does the main thing: it stretches the original data as
	 * defined by the marker object.  Therefore it reads data from odata and
	 * writes to data.
	 */
	_processing = true;

	// setup data
	length = getGuessedLength();
	delete[] data;
	data = new float[length];

	switch (getStretchMode()) {
#ifdef MODE_RUBBERBAND
		case 1: RBprocess(olength, data, marker, this); break;
#endif
		default: {
			for (int i = 0; i < length; ++i) {
				data[i] = getOld(marker->new2old(marker->nnew2new(i / (float)length)));
				setFinished(i / (float)length);
			}
		}
	}

	setFinished(1);
	_processing = false;
	return 0;
}


bool Sample::getProcessing() {
	return _processing;
}


void Sample::setFinished(float f) {
	_finished = f;
}


float Sample::getFinished() {
	return _finished;
}
