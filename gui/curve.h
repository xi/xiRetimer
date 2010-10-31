#ifndef __XICURVE_H
#define __XICURVE_H

#include <iostream>

class Curve {
public:
  Curve(); // irgendwie muss ich das sample da rein bekommen
  ~Curve();
  float get(int i);
  bool selected(int i);
  void setZoom(float z);
  void zoomUp();
  void zoomDown();
  void zoomSel();
  void zoomAll();
  void setlength(int l);
private:
  float zoom;
  int length;  // pixel
  float start; // 0-1
  float starts; //selection
  float ends; //selection
  int datalength;
protected:
  static const float ZOOMFACTOR=1;
  static const float ZOOMSTEP=1.2; // factor used by zoomUp and zoomDown
};

#endif
