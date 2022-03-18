#include "Texture.hh"

Texture::Texture()
{
	// initializing private variables
	texture = nullptr;
	width = 0;
	height = 0;
}

Texture::~Texture() { free(); }

bool Texture::loadFromText(std::string text, SDL_Color color)
{
	this->text = text;

	// get rid the old texture
	free();

	// render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(FontLoader::getFont(), text.c_str(), color);
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

void Texture::render()
{
	// set rendering space and render to screen
	SDL_Rect renderQuad = { Screen::getWidth() / 20, Screen::getHeight() / 4, width, height };

	// render to screen
	SDL_RenderCopy(Renderer::get(), texture, nullptr, &renderQuad);
}


