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
	while (mInputManager->KeyIsDown())
	{
		platform->MoveRight(0.001f, DeltaTime, initialFloorPosition, 15);
	}

}


void Application::Draw()
{
	shader.Clear(projectionLoc, modelLoc, window, angle);
	gMike->Draw(shader);
	platform->Draw(shader);

	shader.Draw();
	window.Swap();
}
