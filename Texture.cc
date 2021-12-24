#include "Texture.hh"

Texture::Texture()
{
	// initializing private variables
	texture = nullptr;
	width = 0;
	height = 0;
}

Texture::~Texture() { free(); }

bool Texture::loadFromFile(std::string path)
{
	// get rid of old texture
	free();

	// the texture
	SDL_Texture* t = nullptr;
	
	// load image from path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if(!loadedSurface)
		std::cout << "Unable to load image " << path.c_str() << " SDL_image Error: " << IMG_GetError() << "\n";
	else
	{
		// set color key
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		// create new texture
		t = SDL_CreateTextureFromSurface(Renderer::get(), loadedSurface);

		if(!t)
			std::cout << "Unable to create texture from " << path.c_str() << " SDL_Error: " << SDL_GetError() << "\n";
		else
		{
			// get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		// get rid of the loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	// return accordingly
	texture = t;
	return texture != nullptr;
}

bool Texture::loadFromText(std::string text, SDL_Color color)
{
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

// set color, set blendmode, set alpha

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	// set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, width, height };

	// set clip rendering dimensions
	if(clip)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	// finally render to screen
	SDL_RenderCopyEx(Renderer::get(), texture, clip, &renderQuad, angle, center, flip);
}


int Texture::getWidth() { return width; }
int Texture::getHeight() { return height; }


