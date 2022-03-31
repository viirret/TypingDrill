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
	total_lines = 0;
	std::string line;
	file.open("words.txt");

	while(std::getline(file, line))
	{
		total_lines++;
		lines.push_back(line);
	}
}

std::string Word::getSentence(int n)
{
	std::string word;
	
	for(int i = 0; i < n; i++)
	{
		word += lines[randomLine(0, total_lines)];
		if(i == 4)
			word.pop_back();
	}

	return word;
}

