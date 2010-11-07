#ifndef __MARKER_H
#define __MARKER_H

#include <iostream>
#include "xiarray.h"

/*
marker works with float values
it mapps old values (o) from 0 (start) to 1 (end) to any new float values (n)
nnew values (nn) are normalized new values
most classes apart from marker use nnew values. Never forget to convert them!
*/
/*
For different modes of interpolation you have to edit 3 functions: 
old2new
new2old - inverse of old2new
getRatio - derivate of old2new
*/

/*
interpolation modes:
0 - LINEAR
// TODO define constants
*/

class Marker {
public:
  Marker();
  ~Marker();
  void reset();
  void add(float pold, float pnew);
  void remove(int pi);
  float getNew(int pi);
  float getOld(int pi);
  void setNew(int pi, float pnew);
  int getLength();
  void print();
  // 0-1 conversion
  float old2new(float o);
  float new2old(float n);
  float new2nnew(float n);
  float nnew2new(float n);
  int getAreaNew(float n);
  int getAreaOld(float o);
  float getLengthf(); // factor by wich the length is changed;
  float getRatio(float o); // factor by wich is stretched on this place;
  int getInterpolationMode();
  void setInterpolationMode(int m);
private:
  xiArray anew;
  xiArray aold;
  int resort(int pi);
  int interpolationMode;
};

/*
int main() {
  Marker m;
  m.add(0.5,0.4);
  std::cout << m.getNew(1) << std::endl;
}
*/

#endif
