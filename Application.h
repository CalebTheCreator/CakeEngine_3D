#pragma once
#define SDL_MAIN_HANDLED
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Window.h"
#include "Shader.h"
#include "Model.h"

struct Application
{
	Application();
	~Application();
	void Run();

private:
	Window window;
	Shader shader;
	Model model;
	GLint projectionLoc;
	GLint modelLoc;
	float angle;
	bool quit = false;
};