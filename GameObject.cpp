#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(const char* modelSrc)
{
	m = Model(modelSrc);
}

GameObject::~GameObject()
{
}

void GameObject::Begin()
{
}

void GameObject::Tick()
{
}
