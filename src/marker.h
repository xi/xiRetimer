#ifndef __MARKER_H
#define __MARKER_H

#include <iostream>
#include "xiarray.h"

/*
 * marker works with float values
 * it mapps old values (o) from 0 (start) to 1 (end) to any new float values (n)
 * nnew values (nn) are normalized new values
 * most classes apart from marker use nnew values. Never forget to convert them!
 */

/*
 * For different modes of interpolation you have to edit 3 functions:
 * old2new
 * new2old - inverse of old2new
 */

/*
 * interpolation modes:
 * 0 - LINEAR
 * // TODO define constants
 */

class Marker {
	public:
		Marker();
		~Marker();
		void reset();
		void add(float pold, float pnew);
		void remove(int pi);
		float getNew(int pi);
		float getOld(int pi);
		void setNew(int pi, float pnew);
		int getLength();
		void print();

		// 0-1 conversion
		float old2new(float o);
		float new2old(float n);
		float new2nnew(float n);
		float nnew2new(float n);

		int getAreaNew(float n);
		int getAreaOld(float o);
		float getLengthf();  // factor by which the length is changed;
		int getInterpolationMode();
		void setInterpolationMode(int m);
		// used by interpolation modes to determine if data has to be updated
		bool _update;

	private:
		xiArray anew;
		xiArray aold;
		int resort(int pi);
		int interpolationMode;
};

#endif
