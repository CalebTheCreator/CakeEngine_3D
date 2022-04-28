#pragma once
#define SDL_MAIN_HANDLED
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Window.h"
#include "Shader.h"
#include "GameObject.h"
#include "InputManager.h"

#include <memory>

struct Application
{
	Application();

	~Application();

	void Tick();

	void Draw();

private:
	Window window;
	Shader shader;
	GameObject* gMike;
	GameObject* platform;
	GLint projectionLoc;
	GLint modelLoc;
	float angle;
	bool quit;
	float xPos1;
	float xPos2;
	InputManager* mInputManager;
	glm::vec3 initialFloorPosition = glm::vec3(0, -10, -70);
	glm::vec3 initialMikePosition = glm::vec3(0, -1.5, -10);
};