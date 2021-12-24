#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "Renderer.hh"
#include "FontLoader.hh"
#include "Texture.hh"
#include "Window.hh"

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
		Renderer::CreateRenderer();

		// initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if(!(IMG_Init(imgFlags) &imgFlags))
			std::cout << "SDL_image could not initialize! SDL_Image Error: " << IMG_GetError() << "\n";
		
		// initialize SDL_ttf
		if(TTF_Init() == -1)
			std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << "\n";

		// load font
		FontLoader::setup();

		// the main texture
		Texture mainTexture;

		// main loop flag
		bool quit = false;

		SDL_Event e;

		while(!quit)
		{
			// handle events on queue
			while(SDL_PollEvent(&e) != 0)
			{
				if(e.type == SDL_QUIT)
				{
					mainTexture.free();
					quit = true;
				}
			}

			// clear screen
			SDL_SetRenderDrawColor(Renderer::get(), 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(Renderer::get());

			// load text here
			// renderer texture

			// update screen
			SDL_RenderPresent(Renderer::get());
		}
	}
	
	// free font
	TTF_CloseFont(FontLoader::getFont());

	// destroy renderer
	SDL_DestroyRenderer(Renderer::get());

	// close SDL
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();;


	return 0;
}
