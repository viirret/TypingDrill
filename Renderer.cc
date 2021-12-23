#include "Renderer.hh"

// the actual renderer
SDL_Renderer* renderer;

// setter and getter
void Renderer::set(SDL_Renderer* _renderer) { renderer = _renderer; }
SDL_Renderer* Renderer::get() { return renderer; }

// make renderer
bool Renderer::CreateRender()
{
	// flag
	bool w = true;
	Window* window = new Window;

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

void Renderer::free()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}



