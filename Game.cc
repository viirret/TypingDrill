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

	// create the first sentence
	createSentence();

	checkIndex = 0;
	close = false;
	drawColor = Color::regular;
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
	restore();
	eventHandler();
	render();
}

void Game::render()
{
	// the background
	Renderer::setColor(64, 64, 64);
	Renderer::clear();

	for(int i = 0; i < (int)textures.size(); i++)
	{
		textures[i].render(30 * i, Screen::getHeight() / 2, colors[i]);
	}

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
			// regular letter written correctly
			if((e.key.keysym.sym == sentence[checkIndex]) || (isspace(sentence[checkIndex]) && e.key.keysym.sym == 32))
			{
				if(isspace(sentence[checkIndex]) && e.key.keysym.sym == 32)
					textures.at(checkIndex).reload("_", drawColor);

				colors[checkIndex] = drawColor;
				checkIndex++;
				drawColor = Color::regular;
			}

			// error in writing
			else
			{
				drawColor = Color::error;
			}
		}
	}
}

void Game::restore()
{
	if(checkIndex == (int)sentence.length())
	{
		checkIndex = 0;
		colors.clear();
		textures.clear();
		createSentence();
	}
}

void Game::createSentence()
{
	sentence = word.getSentence();

	for(int i = 0; i < (int)sentence.length(); i++)
	{
		colors.push_back(Color::white);
		textures.emplace_back(std::string(1, sentence[i]), colors[i]);
	}
}


