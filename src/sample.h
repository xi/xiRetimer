#ifndef __XISAMPLE_H
#define __XISAMPLE_H

#include <sndfile.h>
#include <iostream>
#include "marker.h"
#include <rubberband/RubberBandStretcher.h>

class Sample {
public:
  Sample(Marker* m);
  ~Sample();
  float *data;
  float get(float nn); // nnew
  int getLength();
  int loadFile(const char* filename);
  int writeFile(const char* filename);
  int process();
private:
  int length;
  Marker* marker;
  int olength;
  float *odata;
  SF_INFO sfinfo;
};

/*
int main() {
  Marker* m=new Marker();
  Sample s(m);
  m->add(0.5,0.3);
  int error;
  error=s.loadFile("test.wav");
  error=s.writeFile("testo.wav");
}
*/

#endif
