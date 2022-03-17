#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>
#include "ScreenSize.hh"
#include "Renderer.hh"

class Window
{
	public:
		Window();
		~Window();
		void resize(SDL_Event e);
	private:
		void setSizes() const;
		SDL_Window* window;
		SDL_Renderer* renderer;
		int width;
		int height;
};


#endif
