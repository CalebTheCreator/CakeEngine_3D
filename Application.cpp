#include "Application.h"

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

void Application::Tick()
{
	while (mInputManager->KeyIsDown())
	{
		mInputManager->Update();

		if (mInputManager->GetMovement() == MovementControls::Right)
		{
			platform->MoveRight(0.003f);
			if (platform->GetPosition().x >= 20)
			{
				platform->SetPosition(initialFloorPosition);
			}
		}
		if (mInputManager->GetMovement() == MovementControls::Left)
		{
			platform->MoveLeft(0.003f);
			if (platform->GetPosition().x <= -20)
			{
				platform->SetPosition(initialFloorPosition);
			}
		}
		if (mInputManager->GetMovement() == MovementControls::Jump)
		{
			gMike->Jump(1.0f);
			if (gMike->GetPosition().y <= 5)
			{
				gMike->SetPosition(initialMikePosition);
			}
		}
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
