#include "xiarray.h"


xiArray::xiArray() {
	_length = 0;
	array = new float[getLength()];
}


xiArray::~xiArray() {
	delete[] array;
}


float xiArray::get(int i) {
	if (i >= 0 && i < getLength()) {
		return array[i];
	}
}


void xiArray::set(int i, float v) {
	if (i >= 0 && i <= getLength()) {
		array[i] = v;
	}
}


void xiArray::insert(int i, float v) {
	if (i >= 0 && i <= getLength()) {
		float* tmpArray = new float[getLength() + 1];
		for (int ii = 0; ii < i; ii++) {
			tmpArray[ii] = array[ii];
		}
		tmpArray[i] = v;
		for (int ii = i; ii < getLength(); ii++) {
			tmpArray[ii+1] = array[ii];
		}
		delete[] array;
		array = tmpArray;
		_length++;
	}
}


void xiArray::add(float v) {
	insert(getLength(), v);
}


void xiArray::remove(int i) {
	if (i >= 0 && i < getLength()) {
		float* tmpArray = new float[getLength() - 1];
		for (int ii = 0; ii < i; ii++) {
			tmpArray[ii] = array[ii];
		}
		for (int ii = i+1; ii < getLength(); ii++) {
			tmpArray[ii-1] = array[ii];
		}
		delete[] array;
		array = tmpArray;
		_length--;
	}
}


int xiArray::getLength() {
	return _length;
}


void xiArray::print() {
	std::cout << "[";
	for (int i = 0; i < getLength() - 1; i++) {
		std::cout << get(i) << " ";
	}
	if (getLength() > 0) {
		std::cout << get(getLength() - 1);
	}
	std::cout << "]";
}


void xiArray::println() {
	print();
	std::cout << std::endl;
}
