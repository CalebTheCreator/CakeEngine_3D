#include "Program.h"
#include "Window.h"
#include "Shader.h"
#include "Model.h"


Program::Program()
{

}

Program::~Program()
{

}

void Program::Run()
{
	game.Clear();
	game.UseProgram();
	game.Uniform();
	game.IncreaseAngle();
	game.Draw();
}