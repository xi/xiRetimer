#ifndef __XIARRAY_H
#define __XIARRAY_H

#include <iostream>

/*
This is like the first c++ class I wrote and was more like making an easy start. If anybody wants to eliminate this from the project and replace it with vectors or something lika that, just do as you want.
*/

class xiArray {
public:
  xiArray();
  ~xiArray();
  float get(int i);
  void set(int i, float v);
  void add(float v);
  void insert(int i,float v);
  void remove(int i);
  int getLength();
  void print();
  void println();
private:
  float* array;
  int _length;
};

/*
int main() {
  Buffer b;
  b.insert(0,17);
  b.insert(0,13);
  b.insert(1,9);
  b.remove(1);
  b.println();
}
*/

#endif
