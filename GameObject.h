#pragma once
#include "Model.h"
#include "Shader.h"
#include <glm/ext.hpp>
#include <glm/glm.hpp>

class GameObject
{
public:
	GameObject();
	GameObject(const char* modelSrc);
	~GameObject();
	void Begin();
	void Tick();
	void SetPosition(glm::vec3 p) { Position = p; }
	glm::vec3 GetPosition() { return Position; }

private:
	Model m;
	glm::vec3 Position;
};

