#pragma once
#include "Game.h"
#include <raylib.h>
#include "Player.h"
#include <vector>
#include "Brick.h"
#include "Wall.h"
#include "Stairs.h"
#include "Gold.h"
class Game
{
private:
	bool playing = false;
	const int screenWidth = 800;
	const int screenHeight = 600;
	Vector2 ballPos;
	std::vector<Gold*> coins;
	std::vector<Tile*> map;
	Player* player;
public:
	Game();
	~Game();

	void InitGame();
	void Update();
	void Draw();
	bool IsPlaying() { return WindowShouldClose(); }
};

