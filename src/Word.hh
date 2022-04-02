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
		std::string getSentence(int n);

	private:
		std::ifstream file;
		std::vector<std::string> lines;
		int total_lines;
};

#endif
