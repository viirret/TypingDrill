#include "Game.hh"

Game::Game()
{
	// create window and renderer
	window = new Window;

	// load the font
	FontLoader::setup();

	// create a sentence
	createSentence();

	close = false;
}

Game::~Game()
{
	TTF_CloseFont(FontLoader::getFont());
	Texture::the().free();
	delete window;
}

void Game::update()
{
	eventHandler();
	render();
}

void Game::render()
{
	// the background
	Renderer::setColor(64, 64, 64);
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

void Game::createSentence()
{
	Texture::the().loadFromText(word.getSentence(), Color::regular);
}


