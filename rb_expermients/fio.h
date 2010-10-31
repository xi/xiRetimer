#ifndef __XIFIO_H
#define __XIFIO_H

#include <sndfile.h>
#include <iostream>
#include "../src/marker.h"
#include <rubberband/RubberBandStretcher.h>

using namespace std;

class fio{
  
};

int main() {
  // create marker
  Marker marker;
  marker.add(0,0);
  marker.add(0.05,0.1);
  marker.add(0.5,0.4);
  marker.add(1,0.9);

  // load files

  const char *fileName="test.wav";
  const char *fileNameOut="testo.wav";

  SNDFILE *sndfile;
  SNDFILE *sndfileOut;
  SF_INFO sfinfo;
  SF_INFO sfinfoOut;

  sndfile = sf_open(fileName, SFM_READ, &sfinfo);
    if (!sndfile) {
      cerr << "ERROR: Failed to open input file \"" << fileName << "\": "
      << sf_strerror(sndfile) << endl;
    return 1;
  }

  int channels= sfinfo.channels;

//  int outFrames=int(marker.getRatio()*sfinfo.frames);
  sfinfoOut.channels = sfinfo.channels;
  sfinfoOut.format = sfinfo.format;
//  sfinfoOut.frames = outFrames;
  sfinfoOut.samplerate = sfinfo.samplerate;
  sfinfoOut.sections = sfinfo.sections;
  sfinfoOut.seekable = sfinfo.seekable;

  sndfileOut = sf_open(fileNameOut, SFM_WRITE, &sfinfoOut) ;
  if (!sndfileOut) {
    cerr << "ERROR: Failed to open output file \"" << fileNameOut << "\" for writing: "
    << sf_strerror(sndfileOut) << endl;
    return 1;
  }
  const int bufferLength=100000;  // important
  float ptr[bufferLength];
  float **ibuf = new float *[channels];
  for (size_t i = 0; i < channels; ++i) ibuf[i] = new float[bufferLength/channels];

  // *************************************** 
  //  The reading is seperated in sections between markers and in buffer to save ram
  //
  for (int i=0; i<marker.length()-1; ++i) {
    unsigned long frames=int((marker.getOld(i+1)-marker.getOld(i))*sfinfo.frames*channels); // number of frames to read
    unsigned int count = 0; // # of read frames in this loop
    unsigned long count2 = 0; // # of read frames alltogether
    unsigned int frames2=0; // # of frames to read in this loop
    float ratio=marker.getRatio(i);
    while (count2<frames) {
      if (frames-count2 < bufferLength)
        frames2=frames-count2;
      else
        frames2=bufferLength;
      count = sf_readf_float(sndfile, ptr, frames2/channels);
      count2 += count;
      if (count <=0) break;

      // float[] to **float
      for (int c=0; c<channels; ++c) for (int j=0; j<bufferLength/channels; ++j) ibuf[c][j]=ptr[j*channels+c];

      float **ibuf2 = new float *[channels];
      for (size_t j = 0; j < channels; ++j) ibuf2[j] = new float[int(bufferLength/channels*ratio)];

      RubberBand::RubberBandStretcher ts(sfinfo.samplerate, channels, 0, ratio);
      int avail=int(bufferLength/channels*ratio);
      ts.setMaxProcessSize(count*10);
      ts.study(ibuf, count, true);
      int a1=-1;
      int a2=0;
      while (a1!=a2) {
        ts.process(ibuf, ts.getSamplesRequired(), false);
        a1=a2;
        a2=ts.available();
      }
      ts.process(ibuf, count, true); // hope two times is enough
      ts.retrieve(ibuf2, avail);

      // **float to float[] and cutting
      float ptr2[avail*channels];
      for (size_t c = 0; c < channels; ++c) {
        for (int j = 0; j < avail; ++j) {
          float value = ibuf2[c][j];
          if (value > 1.f) value = 1.f;
          if (value < -1.f) value = -1.f;
          ptr2[j*channels+c] = value;
        }
      }
      for (int j=0; j<channels; ++j) delete[] ibuf2[j];
      delete[] ibuf2;

      // write to file
      sf_write_float(sndfileOut, ptr2, avail*channels);
    }
  }

  for (int i=0; i<channels; ++i) delete[] ibuf[i];
  delete[] ibuf;

  sf_close(sndfile);
  sf_close(sndfileOut);

}

#endif
