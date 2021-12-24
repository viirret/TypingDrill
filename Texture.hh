#ifndef TEXTURE_HH
#define TEXTURE_HH

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "Renderer.hh"
#include "FontLoader.hh"

class Texture
{
	public:
		Texture();
		~Texture();

		// load image from path
		bool loadFromFile(std::string path);
		
		// create image from font string
		bool loadFromText(std::string text, SDL_Color color);

		// called in destructor
		void free();

		// set color modulation
		void setColor(Uint8 r, Uint8 g, Uint8 b);

		// set blending
		void setBlendMode(SDL_BlendMode blending);

		// set alpha modulation
		void setAlpha(Uint8 a);

		// renders texture, set these values in contructor
		void render(int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

		// getters from dimensions of the image
		int getWidth();
		int getHeight();
	
	private:

		// actual texture
		SDL_Texture* texture;

		// image dimemsions
		int width;
		int height;
};

#endif
