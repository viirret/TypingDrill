#ifndef GAME_HH
#define GAME_HH

#include <SDL2/SDL.h>
#include "Window.hh"
#include "FontLoader.hh"

class Game
{
	public:
		Game();
		~Game();
		bool close;
		void update();
	private:
		void render();
		void eventHandler();
		SDL_Event e;
		Window* window;
};

#endif
