#include "Physics.h"
#include "GameObject.h"

#include <iostream>
namespace Cleb 
{
	bool Cleb::IsColliding(GameObject* one, GameObject* two)
	{
		float distance = glm::distance(one->GetPosition(), two->GetPosition());
		if (distance < 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void CollisionResponse(GameObject* obj, const char* brokenModelSrc)
	{
		obj->SetModelSrc(brokenModelSrc);
	}
}