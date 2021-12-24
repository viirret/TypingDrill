#include "TextMaker.hh"

bool TextMaker::Make(std::string text, Texture texture)
{
	bool w = true;
	SDL_Color textColor = { 0, 0, 0 };
	if(!texture.loadFromText(text, textColor))
	{
		std::cout << "Failed to render text texture\n";
		w = false;
	}
	return w;
}
