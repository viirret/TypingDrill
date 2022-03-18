#include "Word.hh"

template<typename T> T randomLine(T from, T to)
{
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<T> dist(from, to);
	return dist(generator);
}

Word::Word()
{
	std::string line;
	file.open("words.txt");
	while(std::getline(file, line))
	{
		total_lines++;
		lines.push_back(line);
	}
}

Word::~Word()
{
	file.close();
}

std::string Word::getSentence()
{
	std::string word;
	
	for(int i = 0; i < 5; i++)
		word += lines[randomLine(0, total_lines)] + " ";

	return word;
}

