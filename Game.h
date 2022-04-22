#pragma once
#include "Window.h"
#include "Shader.h"
#include "Model.h"
#include "RenderTexture.h"

struct Game
{
	Game();
	~Game();
	void Run();
	void Begin();
	void Tick();

	void BindRenderer();
	void Clear();
	void UseProgram();
	void Uniform();
	void IncreaseAngle();
	void Draw();

	bool Quit() { return quit; }
	void SetQuitStatus(bool q) { quit = q; }

private:
	Window window;
	Shader shader;
	Model model;

	GLint projectionLoc;
	GLint modelLoc;

	bool quit;
	float angle;
	rTex::RenderTexture renderer = rTex::RenderTexture(256, 256);

};

