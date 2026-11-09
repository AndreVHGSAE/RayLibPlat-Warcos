#pragma once
#include <raylib.h>
#include "Game.h"
#include <vector>
#include "Tile.h"


class Game
{
private:
	std::vector<Tile*> map;
	bool playing = false;
	const int screenWidth = 800;
	const int screenHeight = 600;
	Vector2 ballPos;
public:
	Game();
	~Game();

	void InitGame();
	void Update();
	void Draw();
	bool IsPlaying() { return WindowShouldClose(); }
};

