#include "Physics.h"
#include "GameObject.h"

#include <iostream>
namespace Cleb 
{
	bool Cleb::IsColliding(GameObject* one, GameObject* two)
	{
		float distance = glm::distance(one->GetPosition(), two->GetPosition());
		if (distance < 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}