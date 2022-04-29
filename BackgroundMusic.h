#pragma once
#include <SDL2/SDL_mixer.h>

class BackgroundMusic
{
public:
	BackgroundMusic(const char* musicSource);
	~BackgroundMusic();
	void Play();

private:
	Mix_Music* backgroundMusic;
};

