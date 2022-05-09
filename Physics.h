#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Physics
{
	bool MovingSphereToPlaneCollision(const glm::vec3& normal, const glm::vec3& centre0, const glm::vec3 centre1, const glm::vec3);
}