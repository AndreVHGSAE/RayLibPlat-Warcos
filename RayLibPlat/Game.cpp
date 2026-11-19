#include "Game.h"
#include "Tile.h"
#include "Gold.h"
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
        map.push_back(new Brick(i * 25, 0, 25));
        map.push_back(new Brick(i * 25, 575, 25));

        coins.push_back(new Gold(300, 300, 25));
    }
    
    ballPos = { (float)screenWidth / 2,(float)screenWidth / 2 };
}

void Game::Update()
{
    if (IsKeyPressed(KEY_SPACE) && runGame == false)
        runGame = true;
    if (runGame == true)
    {
        Player->Update();
    }
}

void Game::Draw()
{
    BeginDrawing();
    if (runGame == true)
    {
        ClearBackground(DARKBLUE);
        DrawText("Ball Moving", 10, 10, 25, BLACK);
        //DrawCircleV(ballPos, 50, RED);
        Player->Update();
        for (auto i : map)
        {
            Player->Collision(*i);
            i->Draw();
        }
        for (auto temp : coins)
        {
            temp->Draw();
            if (Player->CollectGold(*temp))
            {
                    temp->SetIsActive(false);
                    //add points
            }

        }
        Player->Draw();
    }
    else
    {
        ClearBackground(DARKBLUE);
        DrawText("LOAD RUNNER", 350, 300, 25, BLACK);
        DrawText("Press Space to Start", 300, 400, 25, BLACK);
    }
    EndDrawing();
}


