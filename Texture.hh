#ifndef TEXTURE_HH
#define TEXTURE_HH

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "Renderer.hh"
#include "FontLoader.hh"
#include "ScreenSize.hh"
#include "Color.hh"

class Texture
{
	public:
		Texture();
		~Texture();
		void load(std::string word, SDL_Color color);

		// renders texture, set these values in contructor
		void render(int x, int y, SDL_Color color);
			
		void free();

	private:
		// actual texture
		SDL_Texture* texture;
};

#endif
