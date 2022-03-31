#ifndef GAME_HH
#define GAME_HH

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
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
		void restart();
		void setup();
		std::string getAccuracy();
		std::string getSpeed();
		SDL_Event e;
		Window window;
		Word word;
		std::string sentence;
		int checkIndex;
		std::vector<Texture> textures;
		std::vector<SDL_Color> colors;
		SDL_Color drawColor;
		Texture wpm;
		Texture acc;
		int failures;
};

#endif
