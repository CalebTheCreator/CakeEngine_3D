#include "InputManager.h"
#include <SDL2/SDL.h>
#include <iostream>

InputManager::InputManager()
{
	
}

InputManager::~InputManager()
{

}

void InputManager::Update()
{
	/*
		if (state[SDL_SCANCODE_A])
		{
			std::cout << "Left is pressed" << std::endl;
			SetMovement(MovementControls::Left);
		}
		if (state[SDL_SCANCODE_D])
		{
			std::cout << "Right is pressed" << std::endl;
			SetMovement(MovementControls::Right);
		}
		if (state[SDL_SCANCODE_SPACE])
		{
			std::cout << "Jump is pressed" << std::endl;
			SetMovement(MovementControls::Jump);
		}
		*/
}

bool InputManager::KeyIsDown(int key)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);

	return state[key];
}