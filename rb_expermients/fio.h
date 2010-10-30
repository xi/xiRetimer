#ifndef __XIFIO_H
#define __XIFIO_H

#include <sndfile.h>
#include <iostream>
#include "../src/marker.h"

using namespace std;

class fio{

};

int main() {
  // create marker
  Marker marker;
  marker.add(0,0);
  marker.add(1,1);

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

  const int bufferLength=441000;
  float ptr[bufferLength];

  // cut
  for (int i=0; i<marker.length()-1; ++i) {
    int frames=int((marker.getOld(i+1)-marker.getOld(i))*sfinfo.frames*sfinfo.channels); // number of frames to read
    int count = 0;
    int count2 = 0;
    int frames2=-1;
    while (count2<frames) {
      if (frames-count2 < bufferLength)
        frames2=frames-count2;
      else
        frames2=bufferLength;
      count = sf_read_float(sndfile, ptr, frames2);
      count2 += count;
      // time stretch here
      // sf_write_float(sndfileOut, ptr, int(count*ratio));
      sf_write_float(sndfileOut, ptr, count*1);
    }

  }

  sf_close(sndfile);
  sf_close(sndfileOut);

}

#endif
