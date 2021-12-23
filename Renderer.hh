#ifndef RENDERER_HH
#define RENDERER_HH

#include <SDL2/SDL.h>
#include "Window.hh"

namespace Renderer
{
	// set and get
	void set(SDL_Renderer* renderer);
	SDL_Renderer* get();
	
	// create renderer
	bool CreateRender();

	// free memory
	void free();

}

#endif
