#include "Game.h"
#include <SDL2/SDL.h>

Game::Game()
{
	RunningGame = new Application();
	elevatorMusic = new BackgroundMusic("Music/Elevator Music.wav");
}

Game::~Game()
{
	delete RunningGame;
	delete elevatorMusic;
}

void Game::Run()
{

	while (quit == false)
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		DeltaTime = (double)((NOW - LAST) * 1000 / double(SDL_GetPerformanceFrequency()));
		SDL_Event evt;
		while (SDL_PollEvent(&evt))
		{
			if (evt.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		elevatorMusic->Play();
		RunningGame->Tick(DeltaTime);
		RunningGame->Draw();
	}
}