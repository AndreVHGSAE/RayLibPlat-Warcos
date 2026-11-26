#include <iostream>
#include "Game.h"
#include "Tile.h"
#include "Player.h"

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
    player = new Player( 100, 100, 25);
    for (int i = 0; i < 25; i++)
    {
        map.push_back(new Brick(i * 25, 400,25));
        map.push_back(new Wall(i * 25, 500,25));

    }
    for (int i = 0; i < 25; i++)
    {
        map.push_back(new Brick(i * 25, 300, 25));
        map.push_back(new Wall(i * 25, 565, 25));

    }
    for (int i = 0; i < 10; i++)
    {
        map.push_back(new Stairs(25, (i * 10)+275, 25));
    }
    coins.push_back(new Gold(120, 130, 25));
    coins.push_back(new Gold(500, 300, 25));
    coins.push_back(new Gold(100, 100, 25));
    coins.push_back(new Gold(100, 100, 25));
    coins.push_back(new Gold(100, 100, 25));
    coins.push_back(new Gold(100, 100, 25));
    coins.push_back(new Gold(100, 100, 25));
}


void Game::Update()
{
    player->Update();
    if (IsKeyDown(KEY_RIGHT)) ballPos.x += 2;
    if (IsKeyDown(KEY_LEFT)) ballPos.x -= 2;
    if (IsKeyDown(KEY_UP)) ballPos.y -= 2;
    if (IsKeyDown(KEY_DOWN)) ballPos.y += 2;
    if (IsKeyDown(KEY_DOWN)) Brick.
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
    for(auto i : coins)
        {
        i->Draw();
        }
    EndDrawing();
}