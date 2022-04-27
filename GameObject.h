#pragma once
#include "Shader.h"

#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <wavefront/wavefront.h>
#include <GL/glew.h>

#include "Model.h"

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
	WfModel GetModel() { return model.GetModelInUse(); }
	void SetModelSrc(const char* mS);
	GLuint GetVAOId() { return model.GetVAOId();}
	GLuint GetTextureId() { return model.GetTextureId(); }
	GLuint GetVertexCount() { return model.GetVertexCount(); }


private:
	Model model;
	glm::vec3 Position;
};

