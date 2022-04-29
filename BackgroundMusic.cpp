#include "BackgroundMusic.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdexcept>
#include <iostream>

BackgroundMusic::BackgroundMusic(const char* musicSource)
{
	SDL_Init(SDL_INIT_AUDIO);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "Could not play audio, error: " << Mix_GetError() << std::endl;
	}
	backgroundMusic = Mix_LoadMUS(musicSource);
}

BackgroundMusic::~BackgroundMusic()
{
	Mix_Quit();
	Mix_FreeMusic(backgroundMusic);
	backgroundMusic = nullptr;
}

void BackgroundMusic::Play()
{
	if (!Mix_PlayingMusic())
	{
		Mix_PlayMusic(backgroundMusic, -1);
	}
}
