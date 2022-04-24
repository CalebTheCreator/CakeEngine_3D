#include "GameObject.h"
#include <stdexcept>

GameObject::GameObject()
{
}

GameObject::GameObject(const char* modelSrc)
{
	if (WfModelLoad(modelSrc, &Model) != 0)
	{
		throw std::runtime_error("Failed to load model");
	}
}

GameObject::~GameObject()
{
	WfModelDestroy(&Model);
}

void GameObject::Draw()
{
	glBindVertexArray(GetVAOId());
	glBindTexture(GL_TEXTURE_2D, GetTextureId());

	glDrawArrays(GL_TRIANGLES, 0, GetVertexCount());
}

void GameObject::Begin()
{
}

void GameObject::Tick()
{
}
