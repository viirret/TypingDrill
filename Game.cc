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
	failures = 0;
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
	restart();
	eventHandler();
	render();
}

void Game::render()
{
	// the background
	Renderer::setColor(64, 64, 64);
	Renderer::clear();

	// render text
	for(int i = 0; i < (int)textures.size(); i++)
	{
		//int w = textures[i].getWidth();
		textures[i].render(i * 30, Screen::getHeight() / 2, colors[i]);
	}

	// render words per minute
	wpm.render(0, 0, Color::regular);

	// render accuracy
	acc.render(Screen::getWidth() / 2, 0, Color::regular);

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

				SDL_Log("Correct");
			}

			// error in writing
			else
			{
				drawColor = Color::error;
				failures++;
				SDL_Log("Incorrect");
			}
		}
	}
}

void Game::restart()
{
	if(checkIndex == (int)sentence.length())
	{
		std::cout << getAccuracy() << std::endl;

		wpm.reload("Wpm: ", Color::regular);
		
		acc.reload(getAccuracy(), Color::regular);

		setup();
		createSentence();
	}
}

std::string Game::getAccuracy()
{
	std::string accuracy = "Accuracy: ";
	double acc;
	failures > 0 ? acc = (1 - (double)failures / (double)sentence.length()) * 100 : acc = 100;

	int temp = acc;
	double temp2 = acc - temp;

	if(temp2 > 0)
	{
		std::stringstream ss;
		ss << std::fixed << std::setprecision(2) << acc;
		accuracy += ss.str();
	}
	else
		accuracy += std::to_string(temp);

	return accuracy;
}

void Game::setup()
{
	failures = 0;
	checkIndex = 0;
	colors.clear();
	textures.clear();	
}

void Game::createSentence()
{
	sentence = word.getSentence();

	for(int i = 0; i < (int)sentence.length(); i++)
	{
		colors.push_back(Color::white);

		//SDL_Log("%c", sentence[i]);

		textures.emplace_back(std::string(1, sentence[i]), colors[i]);
	}
}


