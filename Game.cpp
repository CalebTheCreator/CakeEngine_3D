#include "Game.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game()
{
	RunningGame = new Application();
	elevatorMusic = new BackgroundMusic("Music/Monsters Inc. Theme - Piano Arrangement-HQ.wav");
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
		NOW = SDL_GetTicks();
		DeltaTime = (double)(NOW - LAST) / 1000.0f;
		LAST = NOW;
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