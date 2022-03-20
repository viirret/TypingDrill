#include "Texture.hh"

Texture::Texture()
{
	// initializing private variables
	texture = nullptr;
	width = 0;
	height = 0;

	for(int i = 97; i <= 122; i++)
		ascii += i;
}

Texture::~Texture() { free(); }

bool Texture::loadFromText(std::string character, SDL_Color color)
{
	// get rid the old texture
	free();

	// render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(FontLoader::getFont(), character.c_str(), color);
	if(!textSurface)
		std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << "\n";
	else
	{
		// create texture from surface pixels
		texture = SDL_CreateTextureFromSurface(Renderer::get(), textSurface);
		if(!texture)
			std::cout << "Unable to create texture from rendered text! SDL_Error: " << SDL_GetError() << "\n";
		else
		{
			// get image dimensions
			width = textSurface->w;
			height = textSurface->h;
		}

		// get rid of the old surface
		SDL_FreeSurface(textSurface);
	}

	// return if success
	return texture != nullptr;
}


void Texture::free()
{
	if(texture)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
		width = 0;
		height = 0;
	}
}

void Texture::render(int x, int y, int index)
{
	// set rendering space
	SDL_Rect renderQuad = { x, y, width, height };

	// render
	SDL_RenderCopy(Renderer::get(), texture, nullptr, &renderQuad);
}


