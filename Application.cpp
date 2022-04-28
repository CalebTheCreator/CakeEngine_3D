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

	platform->SetPosition(initialFloorPosition);
	gMike->SetPosition(initialMikePosition);
}

Application::~Application()
{
	delete gMike;
	delete platform;
}

void Application::Tick()
{
	platform->MoveRight(0.003f);
	if (platform->GetPosition().x >= 20)
	{
		platform->SetPosition(initialFloorPosition);
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
