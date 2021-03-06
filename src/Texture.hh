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
		Texture(std::string word, SDL_Color color);
		Texture(Texture&& tex);
		Texture(){};
		~Texture();
		Texture& operator=(Texture&& other);
		void render(int x, int y, SDL_Color color);
		void reload(std::string word, SDL_Color color);
		int getWidth();
		int getHeight();

	private:
		void load(std::string word, SDL_Color color);
		SDL_Texture* texture = nullptr;
		int width;
		int height;
};

#endif
