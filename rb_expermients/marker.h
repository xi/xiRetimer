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
  int length();
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
  std::cout << m.getNew(3) << std::endl;
}
*/

#endif
