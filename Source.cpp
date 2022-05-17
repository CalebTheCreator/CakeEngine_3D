#include "Game.h"
#include <memory>

int main(int argc, char* argv[])
{
	std::shared_ptr<Game> MikesAdventure = std::make_shared<Game>();

	MikesAdventure->Run();

	return 0;
}