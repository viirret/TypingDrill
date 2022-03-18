#include "FontLoader.hh"

TTF_Font *font;

bool FontLoader::setup()
{
	// flag
	bool w = true;

	// open the font
	font = TTF_OpenFont("font.ttf", 28);

	if(!font)
	{
		std::cout << "Failed to load the font! SDL_ttd Error: " << TTF_GetError() << "\n";
		w = false;
	}

	return w;
}

TTF_Font* FontLoader::getFont() { return font; }
