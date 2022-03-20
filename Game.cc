#include "Game.hh"

Game::Game()
{
	// create window and renderer
	window = new Window;

	// load the font
	FontLoader::setup();

	// create a sentence
	createSentence();

	checkIndex = 0;

	close = false;
}

Game::~Game()
{
	TTF_CloseFont(FontLoader::getFont());
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
	
	text.render(Screen::getWidth() / 20, Screen::getHeight() / 4, 4);

	// main rendering
	Renderer::render();	
}

void Game::eventHandler()
{
	while (SDL_PollEvent(&e))
	{
		window->resize(e);

		if((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) || e.type == SDL_QUIT)
			close = true;
		
		else if(e.type == SDL_KEYDOWN)
		{
			if(e.key.keysym.sym == sentence[checkIndex])
			{
				checkIndex++;
				SDL_Log("%s", "Correct!");
			}
		}
	}
}

void Game::createSentence()
{
	sentence = word.getSentence();
	
	text.loadFromText(sentence, Color::regular);
}


