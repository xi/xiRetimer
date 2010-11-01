#include "buffer.h"

Buffer::Buffer() {
  _length=0;
  array=new float[getLength()];
}

Buffer::~Buffer() {
  delete[] array;
}

float Buffer::get(int i) {
  if (i>=0 && i<getLength())
    return array[i];
  else
    return NULL;
}

void Buffer::set(int i, float v) {
  if (i>=0 && i<=getLength()) array[i]=v;
}

void Buffer::insert(int i,float v) {
  if (i>=0 && i<=getLength()) {
    float* tmpArray=new float[getLength()+1];
    for (int ii=0; ii<i; ii++)
      tmpArray[ii]=array[ii];
    tmpArray[i]=v;
    for (int ii=i; ii<getLength(); ii++)
      tmpArray[ii+1]=array[ii];
    delete[] array;
    array=tmpArray;
    _length++;
  }
}

void Buffer::add(float v) {
  insert(getLength(),v);
}

void Buffer::remove(int i) {
  if (i>=0 && i<getLength()) {
    float* tmpArray=new float[getLength()-1];
    for (int ii=0; ii<i; ii++)
      tmpArray[ii]=array[ii];
    for (int ii=i+1; ii<getLength(); ii++)
      tmpArray[ii-1]=array[ii];
    delete[] array;
    array=tmpArray;
    _length--;
  }
}

int Buffer::getLength() {
  return _length;
}

void Buffer::print() {
  std::cout << "[";
  for (int i=0; i<getLength()-1; i++)
    std::cout << get(i) << " ";
  if (getLength() > 0)
    std::cout << get(getLength()-1);
  std::cout << "]";
}

void Buffer::println() {
  print();
  std::cout << std::endl;
}

