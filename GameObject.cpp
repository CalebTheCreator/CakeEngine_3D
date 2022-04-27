#include "GameObject.h"
#include "Model.h"
#include <stdexcept>

GameObject::GameObject()
{
}

GameObject::GameObject(const char* modelSrc)
{
	model = Model(modelSrc);
}

GameObject::~GameObject()
{
	
}

void GameObject::Draw()
{
	model.Draw();
}

void GameObject::Begin()
{
}

void GameObject::Tick()
{
}

void GameObject::SetModelSrc(const char* mS)
{
	model = Model(mS);
}
