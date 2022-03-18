#include "Game.hh"

Game::Game()
{
	// create window and renderer
	window = new Window;

	// load the font
	FontLoader::setup();

	Texture::the().loadFromText("testi", { 0, 0, 0, 255 });
	
	close = false;
}

Game::~Game()
{
	delete window;
	TTF_CloseFont(FontLoader::getFont());
}


void Game::update()
{
	eventHandler();
	render();
}

void Game::render()
{
	Renderer::setColor(255, 255, 255);
	Renderer::clear();
	
	Texture::the().render();

	Renderer::render();	
}

void Game::eventHandler()
{
	while (SDL_PollEvent(&e))
	{
		window->resize(e);

		if((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) || e.type == SDL_QUIT)
			close = true;
	}
}
