#include "Renderer.hh"

namespace Renderer
{
	// the renderer
	static SDL_Renderer* renderer;

	// setter and getter
	void set(SDL_Renderer* _renderer) { renderer = _renderer; }
	SDL_Renderer* get() { return renderer; }
	
	// render functions
	void setColor(int r, int g, int b) { SDL_SetRenderDrawColor(renderer, r, g, b, 255); }
	void clear() { SDL_RenderClear(renderer); }
	void render() { SDL_RenderPresent(renderer); }
	void fillRect(SDL_Rect r) { SDL_RenderFillRect(renderer, &r); }
}

