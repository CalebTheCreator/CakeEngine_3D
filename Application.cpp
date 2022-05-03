#include "Application.h"
#include <iostream>


Application::Application()
{
	shader = Shader(ShaderType::Specular);
	gMike = new GameObject("models/mike-wazowski/source/Mike Wazowski/Mike.obj");
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
	while (mInputManager->KeyIsDown())
	{
		if (mInputManager->GetMovement() == MovementControls::Jump)
		{

			gMike->Jump(2.0f, DeltaTime, initialMikePosition, NULL);
		}

		if (mInputManager->GetMovement() == MovementControls::Left)
		{
			gMike->MoveLeft(1.0f, DeltaTime, initialMikePosition, -20);
		}

		if (mInputManager->GetMovement() == MovementControls::Right)
		{
			gMike->MoveRight(1.0f, DeltaTime, initialMikePosition, 20);
		}
	}
}


void Application::Draw()
{
	shader.Prepare(projectionLoc, modelLoc, window, angle);
	gMike->Draw(shader);
	platform->Draw(shader);

	shader.Draw();
	window.Swap();
}
