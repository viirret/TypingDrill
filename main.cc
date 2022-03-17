#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "Game.hh"

int main()
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "SDL could not initialize! Error: " << SDL_GetError() << "\n";
	else
	{
		// initialize PNG loading
		if(!(IMG_Init(IMG_INIT_PNG) &IMG_INIT_PNG))
			std::cout << "SDL_image could not initialize! SDL_Image Error: " << IMG_GetError() << "\n";
		
		// initialize SDL_ttf
		if(TTF_Init() == -1)
			std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << "\n";

		Game game;

		while(!game.close)
		{
			game.update();
		}
	}
	
	// close SDL
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}
