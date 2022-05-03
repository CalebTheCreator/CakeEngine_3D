#include "Game.h"

int main(int argc, char* argv[])
{
	Game* MikesAdventure = new Game();

	MikesAdventure->Run();

	delete MikesAdventure;
	
	return 0;
}