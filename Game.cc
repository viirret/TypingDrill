#include "Game.hh"

Game::Game()
{
	// create window and renderer
	window = new Window;

	// load the font
	FontLoader::setup();
	
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
	Renderer::render();	
}

void Game::eventHandler()
{
	while (SDL_PollEvent(&e))
		if((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) || e.type == SDL_QUIT)
			close = true;
}
