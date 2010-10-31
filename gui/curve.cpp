#include "curve.h"

Curve::Curve() {
  length=0;
  start=0;
  zoom=1;
  datalength=100;
}

Curve::~Curve() {}

float Curve::get(int i) {
  float data[100]; // data isnet implemented yet
  int n=int(start*datalength+i*zoom*ZOOMFACTOR);
  if (n>=0 && n<datalength)
    return data[0];
  else
    return 0;
}

bool Curve::selected(int i) {
  int n=int(start*datalength+i*zoom*ZOOMFACTOR);
  return (n>=starts*datalength && n<ends*datalength);
}

void Curve::setZoom(float z) {
  zoom=z;
}

void Curve::zoomUp() {
  setZoom(zoom*ZOOMSTEP);
}

void Curve::zoomDown() {
  setZoom(zoom/ZOOMSTEP);
}

void Curve::zoomSel() {
  start=starts;
  setZoom((ends-starts)*datalength/length/ZOOMFACTOR);
}

void Curve::zoomAll() {
  start=0;
  setZoom(datalength/ZOOMFACTOR/length);
}


void Curve::setlength(int l) {
  length=l;
}
