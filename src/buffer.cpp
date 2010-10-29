#include "buffer.h"

Buffer::Buffer() {
  _length=0;
  array=new float[length()];
}

Buffer::~Buffer() {
  delete[] array;
}

float Buffer::get(int i) {
  if (i>=0 && i<length())
    return array[i];
  else
    return NULL;
}

void Buffer::set(int i, float v) {
  if (i>=0 && i<=length()) array[i]=v;
}

void Buffer::insert(int i,float v) {
  if (i>=0 && i<=length()) {
    float* tmpArray=new float[length()+1];
    for (int ii=0; ii<i; ii++)
      tmpArray[ii]=array[ii];
    tmpArray[i]=v;
    for (int ii=i; ii<length(); ii++)
      tmpArray[ii+1]=array[ii];
    delete[] array;
    array=tmpArray;
    _length++;
  }
}

void Buffer::add(float v) {
  insert(length(),v);
}

void Buffer::remove(int i) {
  if (i>=0 && i<length()) {
    float* tmpArray=new float[length()-1];
    for (int ii=0; ii<i; ii++)
      tmpArray[ii]=array[ii];
    for (int ii=i+1; ii<length(); ii++)
      tmpArray[ii-1]=array[ii];
    delete[] array;
    array=tmpArray;
    _length--;
  }
}

int Buffer::length() {
  return _length;
}

void Buffer::print() {
  std::cout << "[";
  for (int i=0; i<length()-1; i++)
    std::cout << get(i) << " ";
  if (length() > 0)
    std::cout << get(length()-1);
  std::cout << "]";
}

void Buffer::println() {
  print();
  std::cout << std::endl;
}

