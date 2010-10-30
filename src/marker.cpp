#include "marker.h"

Marker::Marker() {
  anew;
  aold;
}

Marker::~Marker() {
}

void Marker::add(float pold, float pnew) {
  anew.add(pnew);
  aold.add(pold);
}
  
void Marker::rm(int pi) {
  anew.remove(resort(pi));
  anew.remove(resort(pi));
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
  if (length()>0)
    return (getNew(length()-1)-getNew(0))/(getOld(length()-1)-getOld(0));
  else
    return NULL;
}

float Marker::getRatio(int i) {
  if (i>=0 && i<length()-1)
    return (getNew(i+1)-getNew(i))/(getOld(i+1)-getOld(i));
  else
    return NULL;
}

int Marker::length() {
  return anew.length();
}

void Marker::println() {
  aold.println();
  anew.println();
}

int Marker::resort(int pi) {
  if (!(pi>=0 && pi<length())) return -1;
  // write anew and indices into arrays
  float tnew[length()];
  int ti[length()];
  for (int i=0; i<length(); i++) {
    tnew[i]=anew.get(i);
    ti[i]=i;
  }
  // sort arrays
  for (int j=0; j<length()-1; j++) {
    for (int i=0; i<length()-1-j; i++) {
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

