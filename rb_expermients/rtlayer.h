#ifndef __XILAYER_H
#define __XILAYER_H

#include <iostream>
#include "../src/marker.h"
#include <rubberband/RubberBandStretcher.h>


class RTlayer {
public:
  RTlayer();
  ~RTlayer();
  Marker marker;
};


int main() {

  RTlayer layer;

  int samples=10000000;
  int sample_rate=44100;
  float* raw=new float[samples];

  layer.marker.add(0,0);
  layer.marker.add(0.4,0.5);
  layer.marker.add(1,1);

  for (int i=0; i<layer.marker.length()-1; i++) {
//    RubberBand::RubberBandStretcher ts(44100, 1);
//    ts.study(raw, raw.length, true);
//    ts.process(raw, raw.length, true);
//    int avail=ts.available();
//    float[] tmpRaw=new tmpRaw[avail];
//    addRaw(ts.recieve(tmpRaw,avail));
  }

}


#endif
