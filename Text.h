/*/#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Window.h"

class Text
{
public:
	Text();
	Text(int size, int w, int h, SDL_Color c, std::string fPath, std::string t, Window window);
	~Text();
	void Draw();

private:
	int fontsize, width, height;
	SDL_Color text_color;
	std::string fontPath, text;
	TTF_Font* font;
	SDL_Texture* ftexture;
	SDL_Surface* text_Surface;

};*/

