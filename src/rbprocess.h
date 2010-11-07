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

int RBprocess(int olength, float* data, Marker* marker, Sample* sample, int n=1) {

  int length=sample->getLength();
  int ostart=int(marker->getOld(0)*olength);
  if (ostart<0) ostart=0;
  int olength2=int(marker->getOld(marker->getLength()-1)*olength)-ostart;
  if (olength2>olength-ostart) olength2=olength-ostart;

  float **ibuf = new float *[1];
  ibuf[0]=new float[olength2];
  for (int i=0; i<olength2; ++i) {
    ibuf[0][i]=sample->getOld((ostart+i)/(float)olength);
  }

  float **obuf = new float *[1];
  obuf[0]=data;

  RubberBand::RubberBandStretcher ts(44100, 1, 0, 1);
  // map // TODO not precise
  std::map<unsigned int, unsigned int> fmap;
  for (int i=0; i<marker->getLength(); ++i) {
    float old= marker->getOld(i);
    float nnew= marker->new2nnew(marker->old2new(old));
    fmap[int(old*olength)-ostart]=int(nnew*length);
  }
  ts.setKeyFrameMap(fmap);

  sample->setFinished(0.03);
  ts.study(ibuf, olength2, true);
  ts.setMaxProcessSize(olength2);
  int a1=-1;
  int a2=0;
  sample->setFinished(0.06);
  ts.process(ibuf, olength2, true);
  sample->setFinished(0.9);

  int avail=ts.available();
  if (avail>length) avail=length;
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

  delete[] ibuf[0];
  delete[] ibuf;
  delete[] obuf;

  return 0;
}

#endif

