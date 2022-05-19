/**#include "Text.h"
#include <stdexcept>
#include <iostream>

Text::Text()
{

}

Text::Text(int size, int w, int h, SDL_Color c, std::string fPath, std::string t, Window window)
{
	fontsize = size;
	width = w;
	height = h;
	text_color = c;
	fontPath = fPath;
	text = t;
	font = TTF_OpenFont(fontPath.c_str(), fontsize);
	ftexture = NULL;

	if (font == NULL)
	{
		std::cerr << "Failed the load the font!\n";
		std::cerr << "SDL_TFF Error: " << TTF_GetError() << "\n";
	}
	else
	{
		text_Surface = TTF_RenderText_Solid(font, text.c_str(), text_color);

		if (text_Surface == NULL)
		{
			std::cerr << "Failed to render text surface!\n";
			std::cerr << "SDL_TTF Error: " << TTF_GetError() << "\n";
		}
		else
		{
			ftexture = SDL_CreateTextureFromSurface(SDL_GetRenderer(window.GetWindow()), text_Surface);

			if (ftexture == NULL)
			{
				std::cerr << "Unable to create texture from rendered text!\n";
			}
			else
			{
				width = text_Surface->w;
				height = text_Surface->h;


				SDL_FreeSurface(text_Surface);
			}

		}
	}


}

Text::~Text()
{
	SDL_FreeSurface(text_Surface);
}*/
