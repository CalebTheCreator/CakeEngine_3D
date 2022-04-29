#include "GameObject.h"
#include "Model.h"
#include <stdexcept>
#include "Shader.h"
#include <glm/ext.hpp>
#include <glm/glm.hpp>

GameObject::GameObject()
{
	abort();
}

GameObject::GameObject(const char* modelSrc) //:
	//model(modelSrc)
{
	model = new Model(modelSrc);
}

GameObject::~GameObject()
{
	
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

void GameObject::MoveLeft(float x, float DeltaTime, glm::vec3 initialPosition, int restraint)
{
	Position.x += x * DeltaTime;
	if (Position.x <= restraint)
	{
		SetPosition(initialPosition);
	}
}

void GameObject::MoveRight(float x, float DeltaTime, glm::vec3 initialPosition, int restraint)
{
	Position.x += x * DeltaTime;
	if (Position.x >= restraint)
	{
		SetPosition(initialPosition);
	}
}

void GameObject::Jump(float jumpVelocity, float DeltaTime, glm::vec3 initialPosition, int restraint)
{
	Position.y += jumpVelocity * DeltaTime;
	if (Position.x >= restraint)
	{
		SetPosition(initialPosition);
	}
}
