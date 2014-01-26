#include "marker.h"
#include "intmode_poly.h"


Marker::Marker() {
	anew;
	aold;
	add(0, 0);
	add(1, 1);
	interpolationMode = 0;
	_update = true;
}


Marker::~Marker() {
}


void Marker::reset() {
	while (getLength() > 0) {
		anew.remove(0);
		aold.remove(0);
	}
	add(0, 0);
	add(1, 1);
}


void Marker::add(float pold, float pnew) {
	if (pold < 0 || pold > 1) {
		std::cerr << "Error in Marker::add" << std::endl;
		std::cerr << "pold not in range" << std::endl;
		return;
	}
	if (getAreaOld(pold) != getAreaNew(pnew)) {
		std::cerr << "Error in Marker::add" << std::endl;
		std::cerr << "Areas not Fitting: ";
		std::cerr << getAreaOld(pold) << " " << getAreaNew(pnew) << std::endl;
		return;
	}
	anew.add(pnew);
	aold.add(pold);
	_update = true;
}


void Marker::remove(int pi) {
	if (getLength() <= 2) {
		return;
	}
	int i = resort(pi);
	anew.remove(i);
	aold.remove(i);
	_update = true;
}


float Marker::getNew(int pi) {
	return anew.get(resort(pi));
}


float Marker::getOld(int pi) {
	return aold.get(resort(pi));
}


void Marker::setNew(int pi, float pnew) {
	anew.set(resort(pi), pnew);
	_update = true;
}


int Marker::getInterpolationMode() {
	return interpolationMode;
}


void Marker::setInterpolationMode(int m) {
	interpolationMode = m;
}


float Marker::getLengthf() {
	if (getLength() > 0) {
		return getNew(getLength() - 1) - getNew(0);
	}
}


float Marker::getRatio(float o) {
	// deprecated
	// derivate of old2new
	// hardcode the derivate to improve performance
	switch (getInterpolationMode()) {
		// linear
		case 0: {
			int i = getAreaOld(o);
			if (i < 0 || i + 1 > getLength() - 1) {
				return 0;
			}
			float dold = (getOld(i + 1) - getOld(i));
			if (dold <= 0) {
				return 0;
			}
			return (getNew(i + 1) - getNew(i)) / dold;
		} break;
		default: {
			// approxmiate ratio
			float n = 100;  // TODO automate this

			float o1 = o - 1 / n;
			if (o1 < 0) {
				o1 = 0;
			}
			if (o1 > 1) {
				return 0;
			}

			float o2 = o + 1 / n;
			if (o2 < 0) {
				return 0;
			}
			if (o2 > 1) {
				o2 = 1;
			}
			if (o2 - o1 <= 0) {
				return 0;
			}

			return ((old2new(o2) - old2new(o1)) / (o2 - o1));
		}
	}
}


int Marker::getLength() {
	return anew.getLength();
}


int Marker::resort(int pi) {
	if (!(pi >= 0 && pi < getLength())) {
		return -1;
	}
	// write anew and indices into arrays
	float tnew[getLength()];
	int ti[getLength()];
	for (int i = 0; i < getLength(); i++) {
		tnew[i] = anew.get(i);
		ti[i] = i;
	}
	// sort arrays
	for (int j = 0; j < getLength() - 1; j++) {
		for (int i = 0; i < getLength() - 1 - j; i++) {
			if (tnew[i] > tnew[i + 1]) {
				// swap
				float ttf;
				ttf = tnew[i];
				tnew[i] = tnew[i + 1];
				tnew[i + 1] = ttf;
				int tti;
				tti = ti[i];
				ti[i] = ti[i + 1];
				ti[i + 1] = tti;
			}
		}
	}
	return ti[pi];
}


float Marker::old2new(float o) {
	// this one does all the interpolation!
	// for performance reasons you should also hard code the interpolation modes
	// to getRatio(float) and new2old
	switch (getInterpolationMode()) {
		// case 0: // linear is default
		case 1: {  // polynominal spline
			return int_poly(this, o);
		} break;
		default: {
			int i = getAreaOld(o);
			if (i < 0 || i + 1 > getLength() - 1) {
				return 0;
			}
			// linear interpolation
			//    n    - n_i        o    - o_i
			//  -------------  =  -------------
			//  n_{i+1} - n_i     o_{i+1} - o_i
			float ret = (o - getOld(i)) / (getOld(i + 1) - getOld(i));
			ret *= getNew(i + 1) - getNew(i);
			ret += getNew(i);
			return ret;
		}
	}
}


float Marker::new2old(float n) {
	// inverse of old2new
	// hardcode the derivate to improve performance
	switch (getInterpolationMode()) {
		// linear
		case 0: {
			int i = getAreaNew(n);
			if (i < 0 || i + 1 > getLength() - 1) {
				return 0;
			}
			float ret = (n - getNew(i)) / (getNew(i + 1) - getNew(i));
			ret *= getOld(i + 1) - getOld(i);
			ret += getOld(i);
			return ret;
		} break;
		default: {
			// TODO
			// approximate o;
			float o = n;
			for (int i = 1; i < 10; ++i) {
				o += (n - old2new(o)) / i;
			}
			return o;
		}
	}
}


float Marker::new2nnew(float n) {
	return (n - getNew(0)) / (getNew(getLength() - 1) - getNew(0));
}


float Marker::nnew2new(float nn) {
	return nn * (getNew(getLength() -1 ) - getNew(0)) + getNew(0);
}


int Marker::getAreaNew(float n) {
	// TODO n = getNew(i)
	for (int i = 0; i < getLength(); ++i) {
		if (n < getNew(i)) {
			return i - 1;
		}
	}
	return getLength()  - 1;
}


int Marker::getAreaOld(float o) {
	// TODO n = getNew(i)
	for (int i = 0; i < getLength(); ++i) {
		if (o < getOld(i)) {
			return i - 1;
		}
	}
	return getLength() - 1;
}


void Marker::print() {
	std::cout << "Marker" << std::endl;
	for (int i = 0; i < getLength(); ++i) {
		std::cout << i << " ";
		std::cout << getOld(i) << " ";
		std::cout << getNew(i) << std::endl;
	}
}
