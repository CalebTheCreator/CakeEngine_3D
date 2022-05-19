#pragma once
#include <SDL2/SDL.h>

#include <GL/glew.h>

#include "Shader.h"


struct Window
{
	Window();
	~Window();
	void Swap();
	int GetWindowHeight();
	int GetWindowWidth();
	SDL_Window* GetWindow() { return window; }

private:
	SDL_Window* window;
};

