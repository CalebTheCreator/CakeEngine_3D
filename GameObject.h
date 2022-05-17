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
	virtual void Tick(float DeltaTime, float upLimit);
	void Draw(Shader& _shader);
	void SetPosition(glm::vec3 p) { Position = p; }
	glm::vec3 GetPosition() { return Position; }
	WfModel GetModel() { return model->GetModelInUse(); }
	void SetModelSrc(const char* mS);
	GLuint GetVAOId() { return model->GetVAOId();}
	GLuint GetTextureId() { return model->GetTextureId(); }
	GLuint GetVertexCount() { return model->GetVertexCount(); }
	void SetScale(glm::vec3 scale) { this->Scale = scale; }
	void SetX(float x) { Position.x = x; }
	void SetY(float y) { Position.y = y; }
	void SetZ(float z) { Position.z = z; }
	void MoveLeft(float DeltaTime);
	void MoveRight(float DeltaTime);
	void MoveForward(float DeltaTime);
	void MoveBack(float DeltaTime);
	//void Jump(float jumpVelocity, float DeltaTime, glm::vec3& initialPosition, int restraint);
	void Jump(float jumpVelocity);


private:
	Model* model;
	glm::vec3 Position;
	glm::vec3 Scale = glm::vec3(1.0f, 1.0f, 1.0f);
	float upVelocity;
};

