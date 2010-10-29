#ifndef __XIBUFFER_H
#define __XIBUFFER_H

#include <iostream>

class Buffer {
public:
  Buffer();
  ~Buffer();
  float get(int i);
  void set(int i, float v);
  void add(float v);
  void insert(int i,float v);
  void remove(int i);
  int length();
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
