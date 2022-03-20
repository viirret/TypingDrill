#ifndef GAME_HH
#define GAME_HH

#include <SDL2/SDL.h>
#include "Window.hh"
#include "FontLoader.hh"
#include "Texture.hh"
#include "Word.hh"
#include "Color.hh"

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
		void createSentence();
		SDL_Event e;
		Window* window;
		Word word;
		Texture text;
		std::string sentence;
		int checkIndex;
};

#endif
