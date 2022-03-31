#ifndef GAME_HH
#define GAME_HH

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <memory>
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
		SDL_Color drawColor;
		int failures, checkIndex;
		
		// letter's associated colors
		std::vector<SDL_Color> colors;
		
		// textures
		std::vector<Texture> textures;
		Texture wpm, acc;

		// time counting
		std::chrono::time_point<std::chrono::system_clock> startTime;
		std::chrono::time_point<std::chrono::system_clock> endTime;

		const int wordCount = 5;
};

#endif
