#ifndef GAME_HH
#define GAME_HH

#include <SDL2/SDL.h>
#include <string>
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
		bool createSentence();
		SDL_Event e;
		Window window;
		Word word;
		std::string sentence;
		int checkIndex;

		std::vector<Texture> textures;
};

#endif
