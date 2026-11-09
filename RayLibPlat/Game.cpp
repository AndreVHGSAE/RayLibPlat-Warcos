#include <iostream>
#include "Game.h"
#include "Tile.h"
#include "Character.h"

Character* player;
Game::Game()
{
	InitWindow(screenWidth, screenHeight, "Plat");
    SetTargetFPS(30);

    player = new Character({ 100, 100 }, 25);
    for (int i = 0; i < 25; i++)
    {
        map.push_back(new Tile(i * 25, 425, 25));
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        player->Update();
        player->Draw();
        for (auto i : map)
        {
            player->Collision(*i);
            i->Draw();
        }
        EndDrawing();
    }
}

Game::~Game()
{
}

void Game::InitGame()
{
	ballPos = { (float)screenWidth / 2,(float)screenWidth / 2 };

    for (int i = 0; i < 25; i++)
    {
        map.push_back(new Tile(i * 25, 425, 25));
    }

    player = new Character({ 10, 10 }, 25);

}


void Game::Update()
{
    if (IsKeyDown(KEY_RIGHT)) ballPos.x += 2;
    if (IsKeyDown(KEY_LEFT)) ballPos.x -= 2;
    if (IsKeyDown(KEY_UP)) ballPos.y -= 2;
    if (IsKeyDown(KEY_DOWN)) ballPos.y += 2;
}

void Game::Draw()
{

    ClearBackground(DARKBLUE);
    DrawText("Ball Moving", 10, 10, 25, BLACK);
    DrawCircleV(ballPos, 50, RED);
    EndDrawing();
}
