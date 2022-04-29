#pragma once
#include "Shader.h"

#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <wavefront/wavefront.h>
#include <GL/glew.h>

#include "Model.h"

struct Shader;

class GameObject
{
public:
	GameObject();
	GameObject(const char* modelSrc);
	~GameObject();
	void Draw(Shader& _shader);
	void SetPosition(glm::vec3 p) { Position = p; }
	glm::vec3 GetPosition() { return Position; }
	WfModel GetModel() { return model->GetModelInUse(); }
	void SetModelSrc(const char* mS);
	GLuint GetVAOId() { return model->GetVAOId();}
	GLuint GetTextureId() { return model->GetTextureId(); }
	GLuint GetVertexCount() { return model->GetVertexCount(); }
	void SetX(float x) { Position.x = x; }
	void SetY(float y) { Position.y = y; }
	void SetZ(float z) { Position.z = z; }
	void MoveLeft(float x) { Position.x -= x; }
	void MoveRight(float x) { Position.x += x; }
	void Jump(float y) { Position.y += y; }


private:
	Model* model;
	glm::vec3 Position;
};

