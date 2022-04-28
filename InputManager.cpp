#include "InputManager.h"
#include <SDL2/SDL.h>

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

std::string InputManager::Update()
{
	SDL_Event evt;
	while (SDL_PollEvent(&evt))
	{
		switch (evt.type)
		{
		case SDL_KeyCode::SDLK_d:
			return "Right";
			break;

		case SDL_KeyCode::SDLK_a:
			return "Left";
			break;

		case SDL_KeyCode::SDLK_SPACE:
			return "Jump";
			break;

		default:
			break;
		}
	}
}






