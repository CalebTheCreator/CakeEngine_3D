#pragma once
#include <SDL2/SDL.h>
#include <string>

class InputManager
{
public:
	InputManager();
	~InputManager();

	//bool KeyDown(SDL_Scancode keyPressed);

	std::string Update();
};

