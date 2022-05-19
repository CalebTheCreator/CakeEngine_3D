#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "GameObject.h"

namespace Cleb
{
	bool IsColliding(GameObject* one, GameObject* two);

	void CollisionResponse(GameObject* player, GameObject* obstacles);
}