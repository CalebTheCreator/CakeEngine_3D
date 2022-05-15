#include "Physics.h"
#include "GameObject.h"

namespace Cleb 
{
	bool Cleb::IsColliding(GameObject* one, GameObject* two)
	{
		if(one->GetPosition().x == two->GetPosition().x && one->GetPosition().y == two->GetPosition().y)
		{
			return true;
		}
		else if (one->GetPosition().x == two->GetPosition().x && one->GetPosition().z == two->GetPosition().z)
		{
			return true;
		}
		else if (one->GetPosition().y == two->GetPosition().y && one->GetPosition().z == two->GetPosition().z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}