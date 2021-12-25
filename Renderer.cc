#include "Renderer.hh"

// the actual renderer
SDL_Renderer* renderer;

// the window
Window* window;

// setter and getter
void Renderer::set(SDL_Renderer* _renderer) { renderer = _renderer; }
SDL_Renderer* Renderer::get() { return renderer; }

// make renderer
bool Renderer::CreateRenderer()
{
	// flag
	bool w = true;

	// create new window
	window = new Window;

	renderer = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!renderer)
	{
		std::cout << "Renderer could not be created! Error: " << SDL_GetError() << "\n";
		w = false;
	}
	// initialize color
	else
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	return w;
}

// free memory
void Renderer::free()
{
	SDL_DestroyRenderer(renderer);
	delete window;
	renderer = nullptr;
	window = nullptr;
}



