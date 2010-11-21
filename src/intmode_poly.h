#ifndef __INTMODE_POLY_H
#define __INTMODE_POLY_H

#include <iostream>
#include "marker.h"

/*
This defines a interpolytion mode used in marker
// TODO doesnt really work yet
// TODO lots of optimisation to do
*/

float** invertMatrix(float** A) {
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

float int_poly(Marker* marker, float old) {
  int i=marker->getAreaOld(old);
  int n=marker->getLength();

  float x1=marker->getOld(i);
  float x2=marker->getOld(i+1);
  float y1=marker->getNew(i);
  float y2=marker->getNew(i+1);
  float d1;
  float d2;
  if (i<=0)
    d1=(marker->getNew(1)-marker->getNew(0))/(marker->getOld(1)-marker->getOld(0));
  else
    d1=(marker->getNew(i-1)-y2)/(marker->getOld(i-1)-x2);
  if (i>=n-2)
    d2=(marker->getNew(n-1)-marker->getNew(n-2))/(marker->getOld(n-1)-marker->getOld(n-2));
  else
    d2=(y1-marker->getNew(i+2))/(x1-marker->getOld(i+2));

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
    float c=(y2-y1)/(x2-x1);
    float d=y1;
    return c*(old-x1)+d;
  }
    

  for (int j=0; j<3; ++j) {
    delete[] M[j];
  }
  delete[] M;

  float a=I[0][0]*d1+I[0][1]*d2+I[0][2]*(y2-y1);
  float b=I[1][0]*d1+I[1][1]*d2+I[1][2]*(y2-y1);
  float c=I[2][0]*d1+I[2][1]*d2+I[2][2]*(y2-y1);
  float d=y1-a*x1*x1*x1-b*x1*x1-c*x1;

  for (int j=0; j<3; ++j) {
    delete[] I[j];
  }
  delete[] I;

/*
std::cout << " a " << a;
std::cout << " b " << b;
std::cout << " c " << c;
std::cout << " d " << d;
std::cout << std::endl;
*/

  return a*old*old*old+b*old*old+c*old+d;
}

#endif
