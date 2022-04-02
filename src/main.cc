#include "Game.hh"

int main(int argc, char* argv[])
{
	Game game;

	while(!game.close)
		game.update();

	return 0;
}
