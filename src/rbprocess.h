#ifndef __RBPROCESS_H
#define __RBPROCESS_H

#include "marker.h"
#include "sample.h"
#include <rubberband/RubberBandStretcher.h>
#include <map>

/*
this is called by sample.process()
this uses the rubberband library
*/

int RBprocess(int olength, float* data, int length, Marker* marker, Sample* caller, int n=1) {
  
  int ostart=int(marker->getOld(0)*olength);
  if (ostart<0) ostart=0;
  int olength2=int(marker->getOld(marker->getLength()-1)*olength)-ostart;
  if (olength2>olength-ostart) olength2=olength-ostart;
  if (olength2<10) return 1;

  float **ibuf = new float *[1];
  ibuf[0]=new float[olength2];
  for (int i=0; i<olength2; ++i) {
    ibuf[0][i]=caller->getOld((ostart+i)/(float)olength);
  }

  float **obuf = new float *[1];
  obuf[0]=data;

  RubberBand::RubberBandStretcher ts(44100, 1, 0, length/(float)olength2);
  // map // TODO not precise
  std::map<unsigned int, unsigned int> fmap;
  for (int i=0; i<marker->getLength(); ++i) {
    fmap[int(marker->getOld(i)*olength2)]=int(marker->getNew(i)*length);
    // additional 
    for (int j=1; j<n; ++j) {
      float old=(marker->getOld(i+1)-marker->getOld(i))*j/(float)n;
      fmap[int(old*olength2)]=int(marker->new2nnew(marker->old2new(old))*length);
    }
  }
  ts.setKeyFrameMap(fmap);

  caller->setFinished(0.03);
  ts.study(ibuf, olength2, true);
  ts.setMaxProcessSize(olength2);
  int a1=-1;
  int a2=0;
  caller->setFinished(0.06);
  while (a1!=a2) {
    int sam=ts.getSamplesRequired();
    if (sam>olength2/10) sam=olength2/10;
    ts.process(ibuf, sam, false);
    a1=a2;
    a2=ts.available();
    caller->setFinished(a2/(float)length*0.8+0.05); // TODO doesnt really work
  }
  caller->setFinished(0.8);
  ts.process(ibuf, olength2, true);
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

  return 0;
}

#endif

