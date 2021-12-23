#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Renderer.hh"

int main()
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "SDL could not initialize! Error: " << SDL_GetError() << "\n";
	else
	{
		// set texture filtering to linear
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			std::cout << "Linear texture filtering not enabled\n";

		// create renderer
		Renderer::CreateRender();

		// initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if(!(IMG_Init(imgFlags) &imgFlags))
			std::cout << "SDL_Image could not initialize! SDL_Image Error: " << IMG_GetError() << "\n";

		// load media here

		// initialize SDL_ttf
		
		// main loop flag
		bool quit = false;

		SDL_Event e;

		while(!quit)
		{
			// handle events on queue
			while(SDL_PollEvent(&e) != 0)
			{
				if(e.type == SDL_QUIT)
					quit = true;
			}

			// clear screen
			SDL_SetRenderDrawColor(Renderer::get(), 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(Renderer::get());

			// update screen
			SDL_RenderPresent(Renderer::get());
		}
	}

	return 0;
}
