#include "Game.h"
#include <SDL2/SDL.h>

Game::Game()
{
	RunningGame = new Application();
}

Game::~Game()
{
	delete RunningGame;
}

void Game::Run()
{
	while (quit == false)
	{
		SDL_Event evt;
		while (SDL_PollEvent(&evt))
		{
			if (evt.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		RunningGame->Tick();
		RunningGame->Draw();
	}
}
