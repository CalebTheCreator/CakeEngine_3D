#pragma once
#include "Application.h"
#include "BackgroundMusic.h"

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	Application* RunningGame;
	bool quit = false;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double DeltaTime = 0;
	BackgroundMusic* elevatorMusic;
};

