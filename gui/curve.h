#ifndef __XICURVE_H
#define __XICURVE_H

#include <iostream>
#include "../src/sample.h"

// main part of the gui
// layer between screen and backend. Converts everything to screen (0-1) values
class Curve {
public:
  Curve(); 
  ~Curve();
  float getSeeker();
  void setSeeker(float nn);
  void setTempo(int bpm);
  int getTempo();
  void print();
  // direct access to sample
  Sample* sample;
  // indirect access to sample
  float get(float nn);
  // indirect access to marker
  void addMarker();
  void removeMarker();
  // TODO indirect acces for drawing
private:
  float seeker; // 0-1
  Marker* marker;
  int tempo; // bpm
};

/*
int main() {
  Marker* m=new Marker();
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
