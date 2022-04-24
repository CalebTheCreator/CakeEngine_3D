#pragma once
#include "Shader.h"
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <wavefront/wavefront.h>
#include <GL/glew.h>

class GameObject
{
public:
	GameObject();
	GameObject(const char* modelSrc);
	~GameObject();
	void Draw();
	void Begin();
	void Tick();
	void SetPosition(glm::vec3 p) { Position = p; }
	glm::vec3 GetPosition() { return Position; }
	WfModel GetModel() { return Model; }
	GLuint GetVAOId() { return Model.vaoId; }
	GLuint GetTextureId() { return Model.textureId; }
	GLuint GetVertexCount() { return Model.vertexCount; }

private:
	WfModel Model;
	glm::vec3 Position;
};

