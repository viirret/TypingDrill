#include "Window.hh"

// constructor and destructor
Window::Window() { createWindow(); }
Window::~Window() { free(); }
SDL_Window* Window::getWindow() { return window; }

bool Window::createWindow()
{
	// flag
	bool w = true;

	// creating the window
	window = SDL_CreateWindow("ProTyper", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Screen::width, Screen::height, SDL_WINDOW_SHOWN);
	
	if(!window)
	{
		std::cout << "Could not create window! Error: " << SDL_GetError() << "\n";
		w = false;
	}
	return w;
}

void Window::free()
{
	SDL_DestroyWindow(window);
	window = nullptr;
}
