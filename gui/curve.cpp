#include "curve.h"

#include <cmath>

Curve::Curve() {
  marker=new Marker();
  sample=new Sample(marker);
  seeker=0;
  tempo=90;
}

Curve::~Curve() {
  delete[] sample;
  delete[] marker;
}

float Curve::get(float nn) {
  // TODO interpolation?
  return sample->get(nn);
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
}

void Curve::removeMarker() {
  int i=marker->getAreaNew(marker->nnew2new(seeker));
  marker->remove(i);
}

void Curve::print() {
  for (int i=0; i<100; ++i) { // 100 or any number 
    for (float j=-1; j<get(i); j+=0.1)
      std::cout << "+";
    if (std::abs(getSeeker()-i)<0.01)
      std::cout << " *";
    std::cout << std::endl;
  }
}


