#include "Texture.hh"

Texture::Texture(std::string word, SDL_Color color) 
{
	// render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(FontLoader::get(), word.c_str(), color);
	if(!textSurface)
		SDL_Log("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	else
	{
		// create texture from surface pixels
		texture = SDL_CreateTextureFromSurface(Renderer::get(), textSurface);
		if(!texture)
			SDL_Log("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());

		// get rid of the old surface
		SDL_FreeSurface(textSurface);
	}
}

Texture::Texture(Texture&& rhs) : texture(rhs.texture)
{
	rhs.texture = nullptr;
}

Texture::~Texture() 
{
	if(texture)
	{
		SDL_DestroyTexture(texture);
	}
}

void Texture::render(int x, int y, SDL_Color color)
{
	SDL_Rect src = { 0, 0, 30, 100 };
	SDL_Rect dst = { x, y, 30, 100 };

	// set correct color
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
		
	SDL_RenderCopy(Renderer::get(), texture, &src, &dst);
}


