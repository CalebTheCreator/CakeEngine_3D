#include "Window.h"

#include <stdexcept>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Model.h"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 700

Window::Window()
{
	//create window
	window = SDL_CreateWindow("Cake Engine 2022",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
	{
		throw std::runtime_error("Failed to create OpenGL context");
	}

	//Initialize glew
	if (glewInit() != GLEW_OK)
	{
		throw std::runtime_error("Failed to initialize glew");
	}
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::Swap()
{
	SDL_GL_SwapWindow(window);
}

int Window::GetWindowHeight()
{
	return WINDOW_HEIGHT;
}

int Window::GetWindowWidth()
{
	return WINDOW_WIDTH;
}