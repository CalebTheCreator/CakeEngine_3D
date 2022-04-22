#include "Input.h"

std::vector<int> Input::keys;
std::vector<int> Input::downKeys;
std::vector<int> Input::upKeys;

Input::Input()
{
	Quit = cmd_s = cmd_a = cmd_w = cmd_d = keyDown = cmd_mouseleft = cmd_mouseleftUp = cmd_mouseright = cmd_mouserightUp = once = cmd_z = cmd_x = cmd_c = false;
}

Input::~Input()
{

}

void Input::Update()
{
	mouseDelta.x = 0;
	mouseDelta.y = 0;

	while (SDL_PollEvent(&eventQueue))
	{
		if (eventQueue.type == SDL_QUIT)
		{
			Quit = 1;
		}
		else if (eventQueue.type == SDL_MOUSEMOTION)
		{
			mouseX = eventQueue.motion.x;
			mouseY = eventQueue.motion.y;

			mouseDelta.x += mouseX - 400;
			mouseDelta.y += mouseY - 300;
		}
		else if (eventQueue.type == SDL_MOUSEBUTTONDOWN && eventQueue.button.button == SDL_BUTTON_RIGHT)
		{
			mouseX = eventQueue.motion.x;
			mouseY = eventQueue.motion.y;
		}
		else if (eventQueue.type == SDL_MOUSEBUTTONUP && eventQueue.button.button == SDL_BUTTON_RIGHT)
		{
			mouseDelta.x = -1;
			mouseDelta.y = -1;
		}
		else if (eventQueue.type == SDL_KEYDOWN)
		{
			if (eventQueue.key.keysym.sym == SDLK_UP || eventQueue.key.keysym.sym == SDLK_w)
			{
				cmd_w = true;
				std::cout << "down mouse button & w!" << std::endl;
			}
		}
	}
}