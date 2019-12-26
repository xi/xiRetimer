#include "playback.h"

struct sample {
	Uint8 *data;
	Uint32 dpos;
	Uint32 dlen;
} sounds;

	Sample* sample;
	float seeker;
	float oseeker;
	bool _play;

Playback::Playback(Sample* s) {
	sample=s;
	_play=false;
	seeker=0;
	oseeker=0;

	extern void callback(void *unused, Uint8 *stream, int len);
	SDL_AudioSpec fmt;

	/* Set 16-bit stereo audio at 22Khz */
	fmt.freq = 44100/2; // TODO dont know why it takes the double sample-.frequenzy here // TODO link it to sample->sfinfo.samplerate
	fmt.format = AUDIO_S16;
	fmt.channels = 1;
	fmt.samples = 1024;
	fmt.callback = callback;
	fmt.userdata = NULL;

	/* Open the audio device and start playing sound! */
	if ( SDL_OpenAudio(&fmt, NULL) < 0 ) {
		fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_PauseAudio(0);
}

Playback::~Playback() {
	SDL_CloseAudio();
}

int Playback::play() {
	if (_play) {
		stop();
		_play=false;
		return 0;
	}
	else {
		int err=start();
		if (err==0) _play=true;
		return err;
	}
}

int Playback::start() {
	SDL_LockAudio();

	int length=sample->getLength();
	Uint8 idata[length];
	for (int i=0; i<length; ++i) {
		idata[i]=int(sample->get(i/(float)length)*128);
	}
	/* Put the sound data in the slot (it starts playing immediately) */
	sounds.dlen = length;
	sounds.data = idata;
	sounds.dpos = int(seeker*length);

	SDL_UnlockAudio();

	return 0;
}

void callback(void *udata, Uint8 *stream, int len) {
	if (_play) {
		if (sounds.dpos==sounds.dlen) {
			_play=false;
			seeker=float(oseeker);
			return;
		}
		Uint32 amount;

		amount = (sounds.dlen-sounds.dpos);
		if ( amount > len ) {
			amount = len;
		}
		SDL_MixAudio(stream, &sounds.data[sounds.dpos], amount, SDL_MIX_MAXVOLUME);
		sounds.dpos += amount;

		seeker=sounds.dpos/(float)sounds.dlen;
	}
}

void Playback::stop() {
	seeker=sounds.dpos/(float)sounds.dlen;
	oseeker=float(seeker);
	SDL_LockAudio();
	sounds.dpos=sounds.dlen;
	SDL_UnlockAudio();
}

void Playback::setSeeker(float nn) {
	seeker=nn;
	oseeker=float(seeker);
	if (_play) {
		SDL_LockAudio();
		sounds.dpos = int(seeker*sounds.dlen);
		SDL_UnlockAudio();
	}
}

float Playback::getSeeker() {
	return seeker;
}

