#pragma once
#include "Application.h"

class Game
{
public:
	Game();
	~Game();
	void Run();

private:
	Application* RunningGame;
	bool quit = false;
};

