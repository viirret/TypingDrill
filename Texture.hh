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

class Texture
{
	public:
		static Texture& the()
		{
			static Texture t;
			return t;
		}

		// create image from font string
		bool loadFromText(std::string text, SDL_Color color);

		// renders texture, set these values in contructor
		void render();
			
		void free();

	private:
		Texture();
		~Texture();

		// actual texture
		SDL_Texture* texture;

		// image dimemsions
		int width;
		int height;

		std::string text;
};

#endif
