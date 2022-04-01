#include "Game.hh"

Game::Game()
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		SDL_Log("SDL could not initialize! Error: %s\n", SDL_GetError());

	// initialize SDL_ttf
	if(TTF_Init() == -1)
		SDL_Log("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());

	// load the font
	FontLoader::setup();

	// create the first sentence
	createSentence();

	// set textures to empty
	wpm.reload("Speed: ", Color::regular);
	acc.reload("Accuracy: ", Color::regular);

	startTime = std::chrono::system_clock::now();

	checkIndex = 0;
	failures = 0;
	lastLetter = 1000;
	close = false;
	drawColor = Color::regular;
}

Game::~Game()
{
	TTF_CloseFont(FontLoader::get());
	
	// close SDL
	TTF_Quit();
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

	int a = 0;
	int b = 0;

	lastLetter = sentence.length();

	// render text
	for(int i = 0; i < (int)textures.size(); i++)
	{
		int w = textures[i].getWidth();

		// first row
		if((Screen::getWidth() / 20 + i * w) <= Screen::getWidth() - Screen::getWidth() / 20)
		{
			textures[i].render(Screen::getWidth() / 20 + i * w, Screen::getHeight() / 2.25, colors[i]);
		}

		// second row
		else if((Screen::getWidth() / 20 + a * w) <= Screen::getWidth() - Screen::getWidth() / 20)
		{
			textures[i].render(Screen::getWidth() / 20 + a * w, Screen::getHeight() / 2, colors[i]);
			a++;
		}

		// third row
		else if((Screen::getWidth() / 20 + b * w) <= Screen::getWidth() - Screen::getWidth() / 20)
		{
			textures[i].render(Screen::getWidth() / 20 + b * w, Screen::getHeight() / 1.80, colors[i]);
			b++;
		}
		else if(i <= lastLetter)
		{
			lastLetter = i;
		}
	}

	if(lastLetter >= 100)
	{
		// render words per minute
		wpm.render(Screen::getWidth() / 20, Screen::getHeight() / 10, Color::regular);

		// render accuracy
		acc.render(Screen::getWidth() / 2, Screen::getHeight() / 10, Color::regular);
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

				if(checkIndex >= lastLetter)
					restart();
			}

			// error in writing
			else
			{
				drawColor = Color::error;
				failures++;
			}
		}
	}
}

void Game::restart()
{
	endTime = std::chrono::system_clock::now();

	wpm.reload(getSpeed(), Color::regular);
	acc.reload(getAccuracy(), Color::regular);

	setup();
	createSentence();
	startTime = std::chrono::system_clock::now();
}

std::string Game::getAccuracy()
{
	std::string accuracy = "Accuracy: ";
	double acc;
	failures > 0 ? acc = (1 - (double)failures / (double)lastLetter) * 100 : acc = 100;

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

std::string Game::getSpeed()
{
	double ans;
	std::string speed = "Speed: ";
	int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
	double seconds = (double)milliseconds / 1000.00;
	ans = 60.00 / seconds * wordCount;

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << ans;
	speed += ss.str();
	speed += " wpm";

	return speed;
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
	sentence = word.getSentence(wordCount);
	textures.resize(sentence.length());

	for(int i = 0; i < (int)sentence.length(); i++)
	{
		colors.push_back(Color::white);

		Texture t(std::string(1, sentence[i]), colors[i]);
		textures[i] = std::move(t);
	}
}


