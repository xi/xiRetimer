#ifndef __XIRBPROCESS_H
#define __XIRBPROCESS_H

#include "marker.h"
#include "sample.h"
#include <rubberband/RubberBandStretcher.h>
#include <map>

/*
this is called by sample.process()
this uses the rubberband library
*/

void RBprocess(float* odata, int olength, float* data, int length, Marker* marker, Sample* caller, int n=1) {
  // TODO other than linear
  
  float **ibuf = new float *[1];
  ibuf[0]=odata;
  float **obuf = new float *[1];
  obuf[0]=data;

  RubberBand::RubberBandStretcher ts(44100, 1, 0, marker->getRatio());
  // map
  std::map<unsigned int, unsigned int> fmap;
  for (int i=0; i<marker->getLength(); ++i) {
    fmap[int(marker->getOld(i)*olength)]=int(marker->getNew(i)*length);
    // additional 
    for (int j=1; j<n; ++j) {
      float old=(marker->getOld(i+1)-marker->getOld(i))*j/(float)n;
      fmap[int(old*olength)]=int(marker->new2nnew(marker->old2new(old))*length);
    }
  }
  ts.setKeyFrameMap(fmap);

  ts.study(ibuf, olength, true);
  ts.setMaxProcessSize(olength);
  int a1=-1;
  int a2=0;
  caller->setFinished(0.05);
  while (a1!=a2) {
    ts.process(ibuf, ts.getSamplesRequired(), false);
    a1=a2;
    a2=ts.available();
    caller->setFinished(a2/(float)length*0.8+0.05); // TODO doesnt work
  }
  ts.process(ibuf, olength, true);
  caller->setFinished(0.95);

  int avail=ts.available();
  ts.retrieve(obuf, avail);

  for (int j=0; j<avail; ++j) {
    float value = obuf[0][j];
    if (value > 1.f) value = 1.f;
    if (value < -1.f) value = -1.f;
    data[j] = value;
  }

  for (int i=avail; i<length; ++i) {
    data[i]=0;
  }

  delete[] ibuf;
  delete[] obuf;

}

#endif

