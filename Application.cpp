#include "Application.h"
#include <iostream>


Application::Application()
{
	shader = Shader(ShaderType::Specular);
	gMike = new GameObject("models/curuthers/curuthers.obj");
	//gMike = new GameObject("models/disney-infinity-mater/source/PC Computer - Disney Infinity - Mater/Mate/Mate.obj");
	platform = new GameObject("models/Platform.obj");
	projectionLoc = glGetUniformLocation(shader.GetProgramId(), "u_Projection");
	modelLoc = glGetUniformLocation(shader.GetProgramId(), "u_Model");
	angle = 0;
	quit = false;
	xPos1 = -2;
	xPos2 = 2;
	mInputManager = new InputManager();
	platform->SetPosition(initialFloorPosition);
	gMike->SetPosition(initialMikePosition);

	
}

Application::~Application()
{
	delete gMike;
	delete platform;
	delete mInputManager;
}

void Application::Tick(float DeltaTime)
{
	mInputManager->Update();
	if (mInputManager->KeyIsDown(SDL_SCANCODE_SPACE))
	{
		gMike->Jump(5);
	}

	if (mInputManager->KeyIsDown(SDL_SCANCODE_A))
	{
		gMike->MoveLeft(DeltaTime);
	}

	if (mInputManager->KeyIsDown(SDL_SCANCODE_D))
	{
		gMike->MoveRight(DeltaTime);
	}

	gMike->Tick(DeltaTime, -1.5);
}


void Application::Draw()
{
	shader.Prepare(projectionLoc, modelLoc, window, angle);
	gMike->Draw(shader);
	platform->Draw(shader);

	shader.Draw();
	window.Swap();
}
