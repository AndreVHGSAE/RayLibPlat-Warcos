#include <iostream>
#include "Game.h"


int main()
{
	Game game;
	game.InitGame();


	while (!game.IsPlaying())
	{
		game.Update();
		game.Draw();
	}
	CloseWindow();
}
