#include "Game.h"
#include "Tile.h"
#include "Character.h"

Game::Game()
{
	InitWindow(screenWidth, screenHeight, "Plat");
    SetTargetFPS(30);
    Player = new Character({400, 100}, 25);
}

Game::~Game()
{
}

void Game::InitGame()
{
    for (int i = 0; i < 50; i++)
    {
        map.push_back(new Brick(i * 25, 425, 25));
        map.push_back(new Stairs(300, i * 25, 25));
        map.push_back(new Wall(775, i * 25, 25));
        map.push_back(new Wall(0, i * 25, 25));
        map.push_back(new Wall(i * 25, 0, 25));
        map.push_back(new Wall(i * 25, 575, 25));
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
    for (auto i : map)
    {
        Player->Collision(*i);
        i->Draw();
    }
    Player->Draw();
    EndDrawing();
}


