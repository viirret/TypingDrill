#ifndef WORD_HH
#define WORD_HH

#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include <SDL2/SDL.h>

class Word
{
	public:
		Word();
		~Word();
		std::string getSentence();

	private:
		std::ifstream file;
		std::vector<std::string> lines;
		int total_lines = 0;
};

#endif
