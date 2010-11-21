#include "curve.h"

Curve::Curve(Marker* m, Sample* s, Playback* p) {
  marker=m;
  sample=s;
  playback=p;
  tempo=90;
  selMarker=-1;
  beatResolution=1;
  _showIntLine=false;
}

Curve::~Curve() {
  delete[] sample;
  delete[] marker;
}

float Curve::get(float nn) {
  return sample->getOld(marker->new2old(marker->nnew2new(nn)));
}

float Curve::getMin(float nn, float l, int n) {
  float min=1;
  for (int i=0; i<n; ++i) {
    float g=get(nn+l*i/(float)n);
    if (g<min) min=g;
  }
  return min;
}

float Curve::getMax(float nn, float l, int n) {
  float max=-1;
  for (int i=0; i<n; ++i) {
    float g=get(nn+l*i/(float)n);
    if (g>max) max=g;
  }
  return max;
}

float Curve::getSeeker() {
  return playback->getSeeker();
}

float Curve::getBars() {
  int beats=sample->getGuessedLength()/(float)sample->sfinfo.samplerate/60/4*tempo;
  if (beats!=0)
    return beats;
  else
    return 1;
}

void Curve::setTempo(int bpm) {tempo=bpm;}
int Curve::getTempo() {return tempo;}

void Curve::setBeatResolution(float n) {beatResolution=n;}
float Curve::getBeatResolution() {return beatResolution;}

void Curve::addMarker() {
  float n=marker->nnew2new(getSeeker());
  marker->add(marker->new2old(n),n);
  selMarker=marker->getAreaNew(n);
}

void Curve::removeMarker() {
  if (selMarker<0) return;
  marker->remove(selMarker);
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

void Curve::clearMarker() {marker->reset();}

