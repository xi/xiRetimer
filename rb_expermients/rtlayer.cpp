#include "rtlayer.h"

RTlayer::RTlayer() {
  marker;
}

RTlayer::~RTlayer() {
}

float RTlayer::getRatio(int i) {
  if (i>=0 && i<marker.length()-1)
    return (marker.getNew(i+1)-marker.getNew(i))/(marker.getOld(i+1)-marker.getOld(i));
  else
    return NULL;
}

