#include "sample.h"

Sample::Sample(Marker* m) {
  marker=m;
  length=0;
  data=new float[0];
  olength=0;
  odata=new float[0];
}

Sample::~Sample() {
  delete[] data;
}

int Sample::getLength() {
  return length;
}

float Sample::get(float nn) {
  // TODO interpolation?
  int i=int((getLength()-1)*nn);
  if (i<0 || i>=getLength()) return NULL;
  return data[i];
}

float Sample::getOld(float o) {
  // TODO interpolation?
  int i=int((olength-1)*o);
  if (i<0 || i>=olength) return NULL;
  return data[i];
}

int Sample::loadFile(const char* fileName) {
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
  olength=sfinfo.frames; // apropriate length
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
  //reads from odata and writes to data
  const int bufferLength=100000;  // important
  float **ibuf = new float *[1];
  ibuf[0]=new float[bufferLength];
  float **obuf = new float *[1];
  int count2=0; // position in odata
  int avail2=0; // position in data
  // setup data
  length=olength*marker->getRatio();
  delete[] data;
  data=new float[length];
  for (int i=0; i<marker->getLength()-1; ++i) {
    float ratio=marker->getRatio(i);
    int count=0; // position in section (o)
    int frames=int((marker->getOld(i+1)-marker->getOld(i))*olength); // length of section (o)
    while (count<frames && count2<olength && avail2<length) {
      // load odata to ibuf
      for (int j=0; j<bufferLength && count2+j<olength; ++j) {
        ibuf[0][j]=odata[count2+j];
        count++;
      }
      count2+=bufferLength;
      // process ibuf
      RubberBand::RubberBandStretcher ts(sfinfo.samplerate, 1, 0, ratio);
      ts.setMaxProcessSize(bufferLength*10);
      ts.study(ibuf, bufferLength, true);
      int a1=-1;
      int a2=0;
      while (a1!=a2) {
        ts.process(ibuf, ts.getSamplesRequired(), false);
        a1=a2;
        a2=ts.available();
      }
      ts.process(ibuf, bufferLength, true); // hope two times is enough
      int avail=ts.available();

      obuf[0]=new float[avail];
      ts.retrieve(obuf, avail);
      // write obuf to data
      for (int j=0; j<avail && j+avail2<length; ++j) {
        float value = obuf[0][j];
        if (value > 1.f) value = 1.f;
        if (value < -1.f) value = -1.f;
        data[j+avail2] = value;
      }
      avail2+=avail;
      delete[] obuf[0];
    }
  }
  delete[] ibuf[0];
  delete[] ibuf;
  delete[] obuf;
}


