#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "controls.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Update();
	void SetMovement(MovementControls mC) { movement = mC; }
	MovementControls GetMovement() { return movement; }
	bool KeyIsDown();

private:
	const Uint8* state; 
	MovementControls movement;
};

