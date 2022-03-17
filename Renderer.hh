#ifndef RENDERER_HH
#define RENDERER_HH

#include <SDL2/SDL.h>

namespace Renderer
{
	SDL_Renderer* get();
	void set(SDL_Renderer* _renderer);

	void setColor(int r, int g, int b);
	void clear();
	void render();
	void fillRect(SDL_Rect r);
}

#endif
