#pragma once
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>

class Input
{
public:
	Input();
	~Input();

	void Update();

	bool Quit;
	
	int mouseX, mouseY;

	bool cmd_mouseleft, cmd_mouseleftUp, cmd_mouseright, cmd_mouserightUp;
	bool cmd_s, cmd_a, cmd_d, cmd_w, cmd_z, cmd_x, cmd_c;
	bool once;

private:
	SDL_Event eventQueue;
	glm::vec2 mouseDelta;

	static bool getKey(int keyCode) { return false; }
	static bool getKeyDown(int keyCode) { return false; }
	static bool getKeyUp(int keyCode) { return false; }

	static std::vector <int> keys;
	static std::vector <int> upKeys;
	static std::vector <int> downKeys;

	bool keyDown;

	void keyboard(unsigned char key);
	void keyboardUp(unsigned char key);

	void _keyboard(int key);
	void _keyboardUp(int key);

};

