#ifndef __XIRBPROCESS_H
#define __XIRBPROCESS_H

#include "marker.h"
#include <rubberband/RubberBandStretcher.h>

/*
this is called by sample.process()
this uses the rubberband library
*/

void RBprocess(float* odata, int olength, float* data, int length, Marker* marker) {
  // TODO better Quality by loading more into the buffer than needed
  
  const int bufferLength=4096;  // important
  float **ibuf = new float *[1];
  ibuf[0]=new float[bufferLength];
  float **obuf = new float *[1];
  int avail2=0; // position in data

  for (int i=0; i<olength; i+=bufferLength) {
    float ratio=marker->getRatio(i/(float)olength);


    // load odata to ibuf
    for (int j=0; j<bufferLength; ++j) {
      if (i+j<olength)
        ibuf[0][j]=odata[i+j];
      else
        ibuf[0][j]=0;
    }

    // process ibuf
    RubberBand::RubberBandStretcher ts(44100, 1, 0, ratio);
    ts.setMaxProcessSize(bufferLength*10);
    ts.study(ibuf, bufferLength, true);
    int a1=-1;
    int a2=0;
    while (a1!=a2) {
      ts.process(ibuf, ts.getSamplesRequired(), false);
      a1=a2;
      a2=ts.available();
    }
    ts.process(ibuf, bufferLength, true);
    int avail=ts.available();
    obuf[0]=new float[avail];
    ts.retrieve(obuf, avail);

    // write obuf to data
    for (int j=0; j<avail && j+avail2<length; ++j) {
      float value = obuf[0][j];
      if (value > 1.f) value = 1.f;
      if (value < -1.f) value = -1.f;
      data[avail2+j] = value;
    }
    avail2+=avail;

    delete[] obuf[0];
  }
  for (int i=avail2; i<length; ++i) {
    data[i]=0;
  }

  delete[] ibuf[0];
  delete[] ibuf;
  delete[] obuf;

}

#endif

