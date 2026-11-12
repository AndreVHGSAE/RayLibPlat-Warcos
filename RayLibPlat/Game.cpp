#include <iostream>
#include "Game.h"
#include "Tile.h"
#include "Character.h"

Game::Game()
{
	InitWindow(screenWidth, screenHeight, "Plat");
    SetTargetFPS(30);

}

Game::~Game()
{
}

void Game::InitGame()
{
	ballPos = { (float)screenWidth / 2,(float)screenWidth / 2 };
    player = new Character({ 100, 100 }, 25);
    for (int i = 0; i < 25; i++)
    {
        map.push_back(new Brick(i * 100, 500,25));
        map.push_back(new Wall(i * 100, 500,35));
        map.push_back(new Stairs(i * 25, 500,69));

    }
}


void Game::Update()
{
    player->Update();
    if (IsKeyDown(KEY_RIGHT)) ballPos.x += 2;
    if (IsKeyDown(KEY_LEFT)) ballPos.x -= 2;
    if (IsKeyDown(KEY_UP)) ballPos.y -= 2;
    if (IsKeyDown(KEY_DOWN)) ballPos.y += 2;
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(DARKBLUE);
    player->Draw();
    for (auto i : map)
    {
        i->Draw();
        player->CollisionCheck(*i);
    }
    EndDrawing();
}