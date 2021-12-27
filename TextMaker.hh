#ifndef TEXTMAKER_HH
#define TEXTMAKER_HH

#include <string>
#include "Texture.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace TextMaker
{
	bool Make(std::string text, Texture texture);
}

#endif
