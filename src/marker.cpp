#include "marker.h"

Marker::Marker() {
  anew;
  aold;
  add(0,0);
  add(1,1);
}

Marker::~Marker() {
}

void Marker::reset() {
  while(getLength()>0) {
    anew.remove(0);
    aold.remove(0);
  }
  add(0,0);
  add(1,1);
}

void Marker::add(float pold, float pnew) {
  if (pold<0 || pold>1) {
    std::cerr << "Error in Marker::add" << std::endl;
    std::cerr << "  pold not in range" << std::endl;
    return;
  }
  if (getAreaOld(pold)!=getAreaNew(pnew)) {
    std::cerr << "Error in Marker::add" << std::endl;
    std::cerr << "  Areas not Fitting: ";
    std::cerr << getAreaOld(pold) << " " << getAreaNew(pnew) << std::endl;
    return;
  }
  anew.add(pnew);
  aold.add(pold);
}
  
void Marker::remove(int pi) {
  if (getLength()<=2) return;
  int i=resort(pi);
  anew.remove(i);
  aold.remove(i);
}

float Marker::getNew(int pi) {
  return anew.get(resort(pi));
}

float Marker::getOld(int pi) {
  return aold.get(resort(pi));
}

void Marker::setNew(int pi, float pnew) {
  anew.set(resort(pi), pnew);
}

float Marker::getRatio() {
  if (getLength()>0)
    return (getNew(getLength()-1)-getNew(0))/(getOld(getLength()-1)-getOld(0));
  else
    return NULL;
}

float Marker::getRatio(int i) {
  if (i>=0 && i<getLength()-1)
    return (getNew(i+1)-getNew(i))/(getOld(i+1)-getOld(i));
  else
    return NULL;
}

int Marker::getLength() {
  return anew.getLength();
}

int Marker::resort(int pi) {
  if (!(pi>=0 && pi<getLength())) return -1;
  // write anew and indices into arrays
  float tnew[getLength()];
  int ti[getLength()];
  for (int i=0; i<getLength(); i++) {
    tnew[i]=anew.get(i);
    ti[i]=i;
  }
  // sort arrays
  for (int j=0; j<getLength()-1; j++) {
    for (int i=0; i<getLength()-1-j; i++) {
      if (tnew[i]>tnew[i+1]) {
        // swap
        float ttf;
        ttf=tnew[i];
        tnew[i]=tnew[i+1];
        tnew[i+1]=ttf;
        int tti;
        tti=ti[i];
        ti[i]=ti[i+1];
        ti[i+1]=tti;
      }
    }
  }
  return ti[pi];
}

float Marker::old2new(float o) {
// converts old 0-1 values to new 0-1 values
  int i=getAreaOld(o);
  // linear interpolation
  //      n    - n_i        o    - o_i
  //   -------------- =  --------------
  //   n_{i+1} - n_i     o_{i+1} - o_i
  return (o-getOld(i))/(getOld(i+1)-getOld(i))*(getNew(i+1)-getNew(i))+getNew(i);
}

float Marker::new2old(float n) {
// see old2new
  int i=getAreaNew(n);
  return (n-getNew(i))/(getNew(i+1)-getNew(i))*(getOld(i+1)-getOld(i))+getOld(i);
}

float Marker::new2nnew(float n) {
  // normalizing
  return (n-getNew(0))/(getNew(getLength()-1)-getNew(0));
}

float Marker::nnew2new(float nn) {
  return nn*(getNew(getLength()-1)-getNew(0))+getNew(0);
}

int Marker::getAreaNew(float n) {
  // TODO n=getNew(i)
  for (int i=0; i<getLength(); ++i)
    if (n<getNew(i)) return i-1;
  return getLength()-1;
}

int Marker::getAreaOld(float o) {
  // TODO n=getNew(i)
  for (int i=0; i<getLength(); ++i)
    if (o<getOld(i)) return i-1;
  return getLength()-1;
}

void Marker::print() {
  std::cout << "Marker" << std::endl;
  for (int i=0; i<getLength(); ++i) {
    std::cout << i << " ";
    std::cout << getOld(i) << " ";
    std::cout << getNew(i) << std::endl;
  }
}


