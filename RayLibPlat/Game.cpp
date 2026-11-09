#include "Game.h"
#include "Tile.h"
#include "Character.h"

Game::Game()
{
	InitWindow(screenWidth, screenHeight, "Plat");
    SetTargetFPS(30);
    Tile1 = new Tile(50, 50, 25);
    Player = new Character({100, 100}, 25);
}

Game::~Game()
{
}

void Game::InitGame()
{
    for (int i = 0; i < 50; i++)
    {
        map.push_back(new Tile(i * 25, 425, 25));
    }
    
    ballPos = { (float)screenWidth / 2,(float)screenWidth / 2 };
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
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawText("Ball Moving", 10, 10, 25, BLACK);
    //DrawCircleV(ballPos, 50, RED);
    Player->Update();
    Player->Draw();
    for (auto i : map)
    {
        Player->Collision(*i);
        i->Draw();
    }
    Tile1->Draw();
    EndDrawing();
}


