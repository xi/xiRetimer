#include "curve.h"

#include <cmath>

// TODO change first and last marker

Curve::Curve() {
  marker=new Marker();
  sample=new Sample(marker);
  seeker=0;
  tempo=90;
  selMarker=-1;
}

Curve::~Curve() {
  delete[] sample;
  delete[] marker;
}

float Curve::get(float nn) {
  // TODO interpolation?
  return sample->getOld(marker->new2old(marker->nnew2new(nn)));
}

float Curve::getSeeker() {return seeker;}
void Curve::setSeeker(float nn) {
  if (nn>=0 && nn<=1) seeker=nn;
}

void Curve::setTempo(int bpm) {tempo=bpm;}
int Curve::getTempo() {return tempo;}

void Curve::addMarker() {
  float n=marker->nnew2new(seeker);
  marker->add(marker->new2old(n),n);
  // update selMarker
/*
  if (n<selMarker) --selMarker;
  if (selMarker>=getMarkerLength()) --selMarker;
*/
  selMarker=marker->getAreaNew(n);
}

void Curve::removeMarker() {
  if (selMarker<0) return;
  marker->remove(selMarker);
  // update selMarker
//  if (selMarker>=getMarkerLength()) --selMarker;
  selMarker=-1;
}

void Curve::setMarker(float nn) {
  if (selMarker<0) return;
  int i=marker->getAreaNew(marker->nnew2new(nn));
  if (i!=selMarker && i!=selMarker-1) return;
  marker->setNew(selMarker,marker->nnew2new(nn));
}

void Curve::selectMarker(int i) {
  selMarker=i;
}

int Curve::getMarkerLength() {return marker->getLength();}
float Curve::getMarker(int i) {return marker->new2nnew(marker->getNew(i));}

void Curve::print() {
  for (int i=0; i<100; ++i) { // 100 or any number 
    for (float j=-1; j<get(i); j+=0.1)
      std::cout << "+";
    if (std::abs(getSeeker()-i)<0.01)
      std::cout << " *";
    std::cout << std::endl;
  }
}

