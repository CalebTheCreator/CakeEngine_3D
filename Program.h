#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "Game.h"

class Program
{
public:
	Program();
	~Program();
	void Run();
	bool IsGameRunning() { return game.Quit(); }
	void Quit() { game.SetQuitStatus(true); }

private:
	Game game;
};

