#include "Game.hh"

Game::Game()
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		SDL_Log("SDL could not initialize! Error: %s\n", SDL_GetError());

	// initialize PNG loading
	if(!(IMG_Init(IMG_INIT_PNG) &IMG_INIT_PNG))
		SDL_Log("SDL_image could not initialize! SDL_Image Error: %s\n", IMG_GetError());

	// initialize SDL_ttf
	if(TTF_Init() == -1)
		SDL_Log("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());

	// load the font
	FontLoader::setup();

	// create a sentence
	if(!createSentence())
		SDL_Log("Could not create sentence! %s\n", SDL_GetError());

	checkIndex = 0;
	close = false;
}

Game::~Game()
{
	TTF_CloseFont(FontLoader::get());

	// close SDL
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
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
		window.resize(e);

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

bool Game::createSentence()
{
	sentence = word.getSentence();

	if(sentence.length() > 0)
		if(text.loadFromText(sentence, Color::regular))
			return true;

	return false;	
}


