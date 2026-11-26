#pragma once
#include "Character.h"
#include "raylib.h"
#include "Brick.h"
class Player :

    public Character
{
private:


public:
    Player(float x, float y, float size);
    ~Player();

    void PlayerCollisionCheck(Brick& t);

    void Update() override;
    void Draw() override;
};

