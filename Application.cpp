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
		obstacles[i]->SetPosition(glm::vec3(3.0f, -5.0f, rand() % -6 -10));
		obstacles[i]->SetScale(glm::vec3(0.3f, 0.3f, 0.3f));
		
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
		gMike->Jump(5);
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
		obstacles[i]->Tick(DeltaTime, 3.0f);
		obstacles[i]->MoveLeft(DeltaTime);
		if (Cleb::IsColliding(gMike, obstacles[i]))
		{
			std::cout << "Collision taking place sir" << std::endl;
			//Cleb::CollisionResponse(obstacles[i], "models/obj-Burning_Cube_by_3DHaupt/Burning_Cube_by_3DHaupt-(Wavefront OBJ).obj");
		}
	}

	
}


void Application::Draw()
{
	shader.Prepare(projectionLoc, modelLoc, window, angle);
	gMike->Draw(shader);
	//collisionCube->Draw(shader);

	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles[i]->Draw(shader);
	}

	platform->Draw(shader);

	shader.Draw();
	window.Swap();
}
