#ifndef __XIMARKER_H
#define __XIMARKER_H

#include <iostream>
#include "buffer.h"

class Marker {
public:
  Marker();
  ~Marker();
  void add(float pold, float pnew);
  void rm(int pi);
  float getNew(int pi);
  float getOld(int pi);
  void setNew(int pi, float pnew);
  float getRatio();
  float getRatio(int i);
  int length();
  void println();
private:
  Buffer anew;
  Buffer aold;
  int resort(int pi);
};

/*
int main() {
  Marker m;
  m.add(0,0);
  m.add(1,1);
  m.add(0.5,0.4);
  std::cout << m.getNew(1) << std::endl;
}
*/

#endif
