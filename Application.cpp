#include "Application.h"
#include "Physics.h"

#include <iostream>
#include <random>

Application::Application()
{
	srand(time(NULL));
	shader = Shader(ShaderType::Specular);
	gMike = new GameObject("models/mike-wazowski/source/Mike Wazowski/Mike.obj");
	platform = new GameObject("models/Platform.obj");
	//collisionCube = new GameObject("models/minecraft-grass-block/source/Minecraft_Grass_Block_OBJ/Grass_Block.obj");
	projectionLoc = glGetUniformLocation(shader.GetProgramId(), "u_Projection");
	modelLoc = glGetUniformLocation(shader.GetProgramId(), "u_Model");
	angle = 0;
	quit = false;
	xPos1 = -2;
	xPos2 = 2;
	mInputManager = new InputManager();
	platform->SetPosition(initialFloorPosition);
	gMike->SetPosition(initialMikePosition);

	for (int i = 0; i < 5; i++)
	{
		obstacles.push_back(new GameObject("models/minecraft-grass-block/source/Minecraft_Grass_Block_OBJ/Grass_Block.obj"));
		obstacles[i]->SetPosition(glm::vec3(3, -1, -10));
		obstacles[i]->SetScale(glm::vec3(0.3f, 0.3f, 0.3f));

		switch (i)
		{
		case 0:
			obstacles[0]->SetZ(-12);
			break;

		case 1:
			obstacles[1]->SetZ(-14);
			break;

		case 2:
			obstacles[2]->SetZ(-16);
			break;

		case 3:
			obstacles[3]->SetZ(-18);
			break;

		case 4:
			obstacles[4]->SetZ(-20);
			break;


		default:
			break;
		}
	}

}

Application::~Application()
{
	delete gMike;
	delete platform;
	delete mInputManager;

	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles.pop_back();
	}
}

void Application::Tick(float DeltaTime)
{

	mInputManager->Update();
	if (mInputManager->KeyIsDown(SDL_SCANCODE_SPACE))
	{
		gMike->Jump(3);
	}

	if (mInputManager->KeyIsDown(SDL_SCANCODE_A))
	{
		gMike->MoveLeft(DeltaTime);
	}

	if (mInputManager->KeyIsDown(SDL_SCANCODE_S))
	{
		gMike->MoveForward(DeltaTime);
	}

	if (mInputManager->KeyIsDown(SDL_SCANCODE_W))
	{
		gMike->MoveBack(DeltaTime);
	}

	if (mInputManager->KeyIsDown(SDL_SCANCODE_D))
	{
		gMike->MoveRight(DeltaTime);
	}

	gMike->Tick(DeltaTime, -1.5f);

	for (int i = 0; i < obstacles.size(); i++)
	{
		
		obstacles[i]->Tick(DeltaTime, -3.0f);
		obstacles[i]->MoveLeft(DeltaTime);
		if (Cleb::IsColliding(gMike, obstacles[i]))
		{
			std::cout << "Collision taking place sir" << std::endl;
			obstacles[i]->SetModelSrc("models/obj-Burning_Cube_by_3DHaupt\Burning_Cube_by_3DHaupt-(Wavefront OBJ).obj");
		}
		if (obstacles[i]->GetPosition().x <= -5 && !Cleb::IsColliding(obstacles[i], gMike))
		{
			obstacles[i]->SetX(5);
		}
	}
}


void Application::Draw()
{
	shader.Prepare(projectionLoc, modelLoc, window, angle);
	gMike->Draw(shader);

	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->Draw(shader);
	}

	platform->Draw(shader);

	shader.Draw();
	window.Swap();
}

