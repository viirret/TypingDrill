#ifndef WINDOW_HH
#define WINDOW_HH

#include "Screen.hh"
#include <SDL2/SDL.h>
#include <iostream>

class Window
{
	public:
		Window();
		~Window();
		SDL_Window* getWindow();
	private:
		bool createWindow();
		void free();
		SDL_Window* window;
};

#endif
