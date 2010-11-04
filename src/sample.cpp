#include "sample.h"
#include "rbprocess.h"

Sample::Sample(Marker* m) {
  marker=m;
  length=0;
  data=new float[0];
  olength=0;
  odata=new float[0];
  stretchMode=-1;
}

Sample::~Sample() {
  delete[] data;
}

int Sample::getLength() {
  return length;
}

int Sample::getGuessedLength() {
  return int(olength*marker->getRatio());
}

float Sample::get(float nn) {
  int i=int(length*nn);
  if (i<0 || i>=length) return NULL;
  return data[i];
}

float Sample::getOld(float o) {
  int i=int((olength-1)*o);
  if (i<0 || i>=olength) return NULL;
  return odata[i];
}

int Sample::getStretchMode() {return stretchMode;}
void Sample::setStretchMode(int m) {stretchMode=m;}

int Sample::loadFile(const char* fileName) {
// TODO multi filetype support
  SNDFILE *sndfile;
  sfinfo;
  // open file
  sndfile = sf_open(fileName, SFM_READ, &sfinfo);
  if (!sndfile) {
    std::cerr << "ERROR: Failed to open input file \"" << fileName << "\": "
    << sf_strerror(sndfile) << std::endl;
    return 1;
  }
  // setup data
  olength=sfinfo.frames; // expected length
  delete[] odata;
  odata=new float[olength];
  
  // read file into data
  float ptr[10240*sfinfo.channels];
  int count2=0;
  while (true) {
    int count = sf_readf_float(sndfile, ptr, 10240);
    if (count <= 0) break;
    // save ptr in data
    // TODO downmix (maybe several options, maybe multichannel support)
    for (int i=0; i<count*sfinfo.channels; i+=sfinfo.channels) {
      odata[count2]=ptr[i];
      count2++;
    }
  }
  sf_close(sndfile);
  olength=count2; // exact length
  // fill data 
  process();
}

int Sample::writeFile(const char* fileNameOut) {  
// TODO multi filetype support
  if (length<=0) {
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

  sndfileOut = sf_open(fileNameOut, SFM_WRITE, &sfinfoOut) ;
  if (!sndfileOut) {
    std::cerr << "ERROR: Failed to open output file \"" << fileNameOut << "\" for writing: "
    << sf_strerror(sndfileOut) << std::endl;
    return 1;
  }
  sf_write_float(sndfileOut, data, length);
  sf_close(sndfileOut);
}

int Sample::process() {
/*
This function does the nmain thing: it stretches the original data as defined by the marker object.
Therefore it reads data from odata and writes to data.
*/
  // setup data
  length=int(marker->getRatio()*olength);
  delete[] data;
  data=new float[length];
  switch (getStretchMode()) {
    // rubberband
    case 0: RBprocess(odata, olength, data, length, marker); break;
    default: {
      for (int i=0; i<length; ++i) {
        data[i]=getOld(marker->new2old(marker->nnew2new(i/(float)length)));
      }
    }
  }

}

