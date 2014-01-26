#ifndef __SAMPLE_H
#define __SAMPLE_H

#include <sndfile.h>
#include <iostream>
#include <pthread.h>
#include "marker.h"

/*
 * Stretchmodes
 * 0 - none (plain sample copy)
 * 1 - rubberband
 * // TODO define constants
 */

class Sample {
	public:
		Sample(Marker* m);
		~Sample();
		float get(float nn);  // nnew
		float getOld(float o);
		int getLength();
		int getGuessedLength();
		int loadFile(const char* filename);
		int writeFile(const char* filename);
		int process();  // implements the main functionality
		SF_INFO sfinfo;
		int getStretchMode();
		void setStretchMode(int m);
		bool getProcessing();
		float getFinished();
		void setFinished(float f);

	private:
		float *data;
		int length;
		Marker* marker;
		int olength;
		float *odata;
		int stretchMode;
		static void * EntryPoint(void*);
		int process_bg();
		bool _processing;
		float _finished;
};

#endif
