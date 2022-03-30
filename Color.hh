#ifndef COLOR_HH
#define COLOR_HH

#include <SDL2/SDL.h>

namespace Color
{
	static SDL_Color regular = { 0, 0, 0, 255 };
	static SDL_Color used = { 100, 100, 100, 255 };
	static SDL_Color error = { 255, 0, 0, 255 };
	static SDL_Color white = { 255, 255, 255, 255 };
}

#endif
