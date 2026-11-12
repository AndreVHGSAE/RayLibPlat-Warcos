#pragma once
#include "Game.h"
#include <raylib.h>
#include "Character.h"
#include <vector>
#include "Brick.h"
class Game
{
private:
	bool playing = false;
	const int screenWidth = 800;
	const int screenHeight = 600;
	Vector2 ballPos;
	std::vector<Tile*> map;
	Character* player;
public:
	Game();
	~Game();

	void InitGame();
	void Update();
	void Draw();
	bool IsPlaying() { return WindowShouldClose(); }
};

