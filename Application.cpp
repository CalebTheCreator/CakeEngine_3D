#include "Application.h"
#include "Physics.h"

#include <iostream>


Application::Application()
{
	shader = Shader(ShaderType::Specular);
	gMike = new GameObject("models/mike-wazowski/source/Mike Wazowski/Mike.obj");
	platform = new GameObject("models/Platform.obj");
	collisionCube = new GameObject("models/minecraft-grass-block/source/Minecraft_Grass_Block_OBJ/Grass_Block.obj");
	projectionLoc = glGetUniformLocation(shader.GetProgramId(), "u_Projection");
	modelLoc = glGetUniformLocation(shader.GetProgramId(), "u_Model");
	angle = 0;
	quit = false;
	xPos1 = -2;
	xPos2 = 2;
	mInputManager = new InputManager();
	platform->SetPosition(initialFloorPosition);
	gMike->SetPosition(initialMikePosition);
	collisionCube->SetPosition(glm::vec3(initialCubePosition));
	collisionCube->SetScale(glm::vec3(0.3, 0.3, 0.3));
	//SpawnObstacles();
}

Application::~Application()
{
	delete gMike;
	delete collisionCube;
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

	//collisionCube->Tick(DeltaTime, 3.0f);
	//collisionCube->MoveLeft(DeltaTime);
	if (collisionCube->GetPosition().x == -5)
	{
		collisionCube->MoveRight(DeltaTime);
		if (collisionCube->GetPosition().x == 5)
		{
			collisionCube->MoveLeft(DeltaTime);
		}
	}

	gMike->Tick(DeltaTime, -1.5f);
	collisionCube->MoveLeft(DeltaTime);
	if (Cleb::IsColliding(gMike, collisionCube))
	{
		std::cout << "Colliding" << std::endl;
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

void Application::SpawnObstacles()
{
	/*for (int i = 0; i < obstacles.size(); i++)
	{
		float randZ = rand() % -20 + 30;
		obstacles[i]->SetPosition(glm::vec3(-1.0f, -2.0f, randZ));
		obstacles[i]->SetScale(glm::vec3(0.3, 0.3, 0.3));
	}*/

}
