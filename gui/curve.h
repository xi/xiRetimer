#ifndef __XICURVE_H
#define __XICURVE_H

#include <iostream>
#include "../src/sample.h"

class Curve {
public:
  Curve(Sample* s); 
  ~Curve();
  float get(int i);
  float getSeeker();
  void setSeeker(float s);
  void setScreenWidth(int w);
  void print();
private:
  int screenwidth;  // pixel
  float seeker; // 0-1
  float* data;
  int getDataLength();
  Sample* sample;
};

/*
int main() {
  Marker* m=new Marker();
  m->add(0,0);
  m->add(1,1);
  Sample* s=new Sample(m);
  m->add(0.5,0.3);
  int error;
  error=s->loadFile("../../test.wav");
  
  Curve c(s);
  c.setScreenWidth(100);
  c.print();
}
*/

#endif
