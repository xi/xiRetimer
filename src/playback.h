#ifndef __PLAYBACK_H
#define __PLAYBACK_H

#include <iostream>

#include "SDL.h"
#include "SDL_audio.h"

#include "sample.h"

class Playback {
public:
  Playback(Sample* s);
  ~Playback();
  int play();
  void setSeeker(float nn);
  float getSeeker();
private:
  int start();
  void stop();
};

#endif
