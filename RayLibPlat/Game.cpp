#include "Game.h"

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
    DrawCircleV(ballPos, 50, RED);
    EndDrawing();
}
