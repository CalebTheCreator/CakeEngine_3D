#include "GameObject.h"
#include "Model.h"
#include <stdexcept>
#include "Shader.h"
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <iostream>

GameObject::GameObject()
{
	abort();
}

GameObject::GameObject(const char* modelSrc) //:
	//model(modelSrc)
{
	model = new Model(modelSrc);
	upVelocity = 0.0f;

}

GameObject::~GameObject()
{
	
}

void GameObject::Tick(float DeltaTime, float upLimit)
{
	
	Position.y += upVelocity * DeltaTime;
	upVelocity -= 5.0f * DeltaTime;
	if (Position.y < upLimit)
	{
		Position.y = upLimit;
		upVelocity = 0.0f;
	}
	if (Position.y > 3)
	{
		Position.y -= upVelocity * DeltaTime;
		upVelocity = 0.0f;
	}
	//std::cout << upVelocity << std::endl;
	//Position.x += DeltaTime;
}

void GameObject::Draw(Shader& _shader)
{
	glUseProgram(_shader.GetProgramId());
	glUniformMatrix4fv(glGetUniformLocation(_shader.GetProgramId(), "u_Model"), 1, GL_FALSE, glm::value_ptr(
		glm::translate(glm::mat4(1.0f), Position)));

	model->Draw();
}

void GameObject::SetModelSrc(const char* mS)
{
	model = new Model(mS);
}

void GameObject::MoveLeft(float DeltaTime)
{
	Position.x -= DeltaTime;
}

void GameObject::MoveRight(float DeltaTime)
{
	Position.x += DeltaTime;
}

void GameObject::Jump(float jumpVelocity)
{
	upVelocity = jumpVelocity;
}
