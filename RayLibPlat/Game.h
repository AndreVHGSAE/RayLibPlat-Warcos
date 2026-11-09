#pragma once
#include <raylib.h>
#include "Tile.h"
#include "Character.h"
#include <vector>

class Game
{
private:
	Tile* Tile1;
	Character* Player;

	bool playing = false;
	const int screenWidth = 800;
	const int screenHeight = 600;
	Vector2 ballPos;

	std::vector<Tile*> map;
public:
	Game();
	~Game();

	void InitGame();
	void Update();
	void Draw();
	bool IsPlaying() { return WindowShouldClose(); }
};

