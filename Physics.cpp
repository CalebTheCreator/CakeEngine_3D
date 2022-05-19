#include "Physics.h"
#include "GameObject.h"

#include <iostream>
namespace Cleb 
{
	bool Cleb::IsColliding(GameObject* one, GameObject* two)
	{
		float distance = glm::distance(one->GetPosition(), two->GetPosition());
		if (distance < 0.5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void CollisionResponse(GameObject* player, GameObject* obstacle)
	{
		player->SetX(obstacle->GetPosition().x - 0.5);
	}
}