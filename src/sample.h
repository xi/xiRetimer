#ifndef __XISAMPLE_H
#define __XISAMPLE_H

#include <sndfile.h>
#include <iostream>
#include "marker.h"

/*
Stretchmodes
0 - none (plain sample copy)
1 - rubberband
// TODO define constants
*/

class Sample {
public:
  Sample(Marker* m);
  ~Sample();
  float get(float nn); // nnew
  float getOld(float o);
  int getLength();
  int getGuessedLength();
  int loadFile(const char* filename);
  int writeFile(const char* filename);
  int process(); // implements the main functionality
  SF_INFO sfinfo;
  int getStretchMode();
  void setStretchMode(int m);
private:
  float *data;
  int length;
  Marker* marker;
  int olength;
  float *odata;
  int stretchMode;
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
