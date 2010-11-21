#ifndef __INTMODE_POLY_H
#define __INTMODE_POLY_H

#include <iostream>
#include "marker.h"

/*
This defines a interpolytion mode used in marker
*/

namespace _IntPoly {
  void update(Marker* marker, int pi);
  float calculate(float x);
  float** invertMatrix(float** A);
  float a=0,b=0,c=0,d=0;
  int IPi,IPn;
}

float int_poly(Marker* marker, float old) {
  int ii=marker->getAreaOld(old);
  if (marker->_update || ii!=_IntPoly::IPi) _IntPoly::update(marker,ii);
  marker->_update=false;
  return _IntPoly::calculate(old);
}

//*********************************************************************//

float _IntPoly::calculate(float x) {
  return _IntPoly::a*x*x*x+_IntPoly::b*x*x+_IntPoly::c*x+_IntPoly::d;
}

void _IntPoly::update(Marker* marker, int pi) {
  IPn=marker->getLength();
  IPi=pi;
  float x1=marker->getOld(IPi);
  float x2=marker->getOld(IPi+1);
  float y1=marker->getNew(IPi);
  float y2=marker->getNew(IPi+1);
  float d1;
  float d2;
  if (IPi<=0)
    d1=(marker->getNew(1)-marker->getNew(0))/(marker->getOld(1)-marker->getOld(0));
  else
    d1=(marker->getNew(IPi-1)-y2)/(marker->getOld(IPi-1)-x2);
  if (IPi>=IPn-2)
    d2=(marker->getNew(IPn-1)-marker->getNew(IPn-2))/(marker->getOld(IPn-1)-marker->getOld(IPn-2));
  else
    d2=(y1-marker->getNew(IPi+2))/(x1-marker->getOld(IPi+2));

  float** M=new float*[3];
  for (int j=0; j<3; ++j) {
    M[j]=new float[3];
  }

  M[0][0]=3*x1*x1;
  M[0][1]=2*x1;
  M[0][2]=1;

  M[1][0]=3*x2*x2;
  M[1][1]=2*x2;
  M[1][2]=1;

  M[2][0]=x2*x2*x2-x1*x1*x1;
  M[2][1]=x2*x2-x1*x1;
  M[2][2]=x2-x1;

  float** I=invertMatrix(M);

  int zeros=0;
  for (int j=0; j<3; ++j) {
    for (int jj=0; jj<3; ++jj) {
      if (I[j][jj]==0) zeros++;
    }
  }
  if (zeros==9) {
    a=0;
    b=0;
    c=(y2-y1)/(x2-x1);
    d=y1;
    return;
  }
    

  for (int j=0; j<3; ++j) {
    delete[] M[j];
  }
  delete[] M;

  _IntPoly::a=I[0][0]*d1+I[0][1]*d2+I[0][2]*(y2-y1);
  _IntPoly::b=I[1][0]*d1+I[1][1]*d2+I[1][2]*(y2-y1);
  _IntPoly::c=I[2][0]*d1+I[2][1]*d2+I[2][2]*(y2-y1);
  _IntPoly::d=y1-_IntPoly::a*x1*x1*x1-_IntPoly::b*x1*x1-_IntPoly::c*x1;

  for (int j=0; j<3; ++j) {
    delete[] I[j];
  }
  delete[] I;
}

float** _IntPoly::invertMatrix(float** A) {
  float** X=new float*[3];
  for (int i=0; i<3; ++i) {
    X[i]=new float[3];
  }
  int i,j;
  float n=0; // determinant of A

  n+=A[0][0]*A[1][1]*A[2][2];
  n+=A[0][1]*A[1][2]*A[2][0];
  n+=A[0][2]*A[1][0]*A[2][1];

  n-=A[0][0]*A[1][2]*A[2][1];
  n-=A[0][1]*A[1][0]*A[2][2];
  n-=A[0][2]*A[1][1]*A[2][0];
     
  if(n*n<=0.00000000001) {
    for (int i=0; i<3; ++i) {
      for (int j=0; j<3; ++j) {
        X[i][j]=0;
      }
    }
    return X;
  }

  X[0][0]=A[1][1]*A[2][2]-(A[2][1]*A[1][2]);
  X[1][0]=(-1)*(A[1][0]*A[2][2]-(A[2][0]*A[1][2]));
  X[2][0]=A[1][0]*A[2][1]-(A[2][0]*A[1][1]);
     
  X[0][1]=(-1)*(A[0][1]*A[2][2]-A[2][1]*A[0][2]);
  X[1][1]=A[0][0]*A[2][2]-A[0][2]*A[2][0];
  X[2][1]=(-1)*(A[0][0]*A[2][1]-A[2][0]*A[0][1]);
 
  X[0][2]=A[0][1]*A[1][2]-A[1][1]*A[0][2];
  X[1][2]=(-1)*(A[0][0]*A[1][2]-A[1][0]*A[0][2]);
  X[2][2]=A[0][0]*A[1][1]-A[1][0]*A[0][1];

  for(i=0;i<3;i++) {
    for(j=0;j<3;j++) {
      X[i][j]=X[i][j]/n;
    }
  }
 
  return X;
} 

#endif
