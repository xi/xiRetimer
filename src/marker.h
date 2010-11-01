#ifndef __XIMARKER_H
#define __XIMARKER_H

#include <iostream>
#include "buffer.h"

/*
marker works with float values
it mapps old values from 0 (start) to 1 (end) to any new float values
nnew values are normalized new values
most classes apart from marker use nnew values. Never forget to convert them!
*/

class Marker {
public:
  Marker();
  ~Marker();
  void add(float pold, float pnew);
  void remove(int pi);
  float getNew(int pi);
  float getOld(int pi);
  void setNew(int pi, float pnew);
  float getRatio(); // factor by wich the whole sample is stretched; used to guess the length of the output array;
  float getRatio(int i); // factor by wich the is area is stretched;
  int getLength();
  void println();
  // 0-1 conversion
  float old2new(float o);
  float new2old(float n);
  float new2nnew(float n);
  float nnew2new(float n);
  int getAreaNew(float n);
  int getAreaOld(float o);
private:
  Buffer anew;
  Buffer aold;
  int resort(int pi);
};

/*
int main() {
  Marker m;
  m.add(0.5,0.4);
  std::cout << m.getNew(1) << std::endl;
}
*/

#endif
