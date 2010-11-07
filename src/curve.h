#ifndef __CURVE_H
#define __CURVE_H

#include <iostream>
#include "marker.h"
#include "sample.h"
#include "playback.h"

// main part of the gui
// layer between screen and backend. Converts everything to screen (0-1) values
class Curve {
public:
  Curve(Marker* m, Sample* s, Playback* p); 
  ~Curve();
  // indirect access to playback
  float getSeeker();
  // indirect access to sample
  float get(float nn);
  float getMin(float nn, float l, int n=10); // nicer looking waveform
  float getMax(float nn, float l, int n=10); // nicer looking waveform
  // indirect access to marker
  void addMarker();
  void removeMarker();
  int getMarkerLength();
  float getMarker(int i);
  void selectMarker(int i);
  void setMarker(float nn);
  void clearMarker();
  // bars
  float getBars();
  void setBeatResolution(float n);
  float getBeatResolution();
  void setTempo(int bpm);
  int getTempo();
private:
  Marker* marker;
  Sample* sample;
  Playback* playback;
  int tempo; // bpm
  int selMarker;
  float beatResolution;
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
