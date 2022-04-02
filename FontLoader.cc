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
		SDL_Log("Failed to load the font! SDL_ttf Error: %s\n", TTF_GetError());
		w = false;
	}

	return w;
}

TTF_Font* FontLoader::get() { return font; }
