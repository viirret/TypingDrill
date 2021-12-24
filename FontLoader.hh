#ifndef FONTLOADER_HH
#define FONTLOADER_HH

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

namespace FontLoader
{
	bool setup();
	TTF_Font* getFont();
}

#endif
