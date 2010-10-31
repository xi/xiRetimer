#include "curve.h"

Curve::Curve(Sample* s) {
  sample=s;
  data=sample->data;
  screenwidth=0;
  seeker=0;
}

Curve::~Curve() {}

float Curve::get(int i) {
  int n=int((float)i/screenwidth*getDataLength());
  if (n>=0 && n<getDataLength())
    return data[n];
  else
    return 0;
}

float Curve::getSeeker() {return seeker;}
void Curve::setSeeker(float s) {
  if (s>=0 && s<=1) seeker=s;
}

void Curve::setScreenWidth(int w) {screenwidth=w;}

void Curve::print() {
  for (int i=0; i<screenwidth; ++i) {
    for (float j=-1; j<get(i); j+=0.1)
      std::cout << "+";
    if (getSeeker()==i)
      std::cout << " *";
    std::cout << std::endl;
  }
}

inline int Curve::getDataLength() {
  return sample->getLength();
}
