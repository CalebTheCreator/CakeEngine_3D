#include "Application.h"
#include "Physics.h"

#include <iostream>


Application::Application()
{
	shader = Shader(ShaderType::Specular);
	gMike = new GameObject("models/mike-wazowski/source/Mike Wazowski/Mike.obj");
	platform = new GameObject("models/Platform.obj");
	collisionCube = new GameObject("models/cube.obj");
	projectionLoc = glGetUniformLocation(shader.GetProgramId(), "u_Projection");
	modelLoc = glGetUniformLocation(shader.GetProgramId(), "u_Model");
	angle = 0;
	quit = false;
	xPos1 = -2;
	xPos2 = 2;
	mInputManager = new InputManager();
	platform->SetPosition(initialFloorPosition);
	gMike->SetPosition(initialMikePosition);
	collisionCube->SetPosition(initialCubePosition);
}

Application::~Application()
{
	delete gMike;
	delete platform;
	delete collisionCube;
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

	collisionCube->Tick(DeltaTime, 3.0f);

	gMike->Tick(DeltaTime, -1.5f);

	if (Cleb::IsColliding(gMike, collisionCube))
	{
		std::cout << "Collision is taking place bro" << std::endl;
	}
}


void Application::Draw()
{
	shader.Prepare(projectionLoc, modelLoc, window, angle);
	gMike->Draw(shader);
	collisionCube->Draw(shader);
	platform->Draw(shader);

	shader.Draw();
	window.Swap();
}
