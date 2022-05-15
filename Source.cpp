#include "Game.h"
#include <memory>

int main(int argc, char* argv[])
{
	//creating smart pointer to run game
	std::weak_ptr<Game> weakGame;

	std::shared_ptr<Game> MikesAdventure = std::make_shared<Game>();

	MikesAdventure->Run();

	weakGame = MikesAdventure;
	weakGame.lock()->Run();

	return 0;
}