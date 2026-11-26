#pragma once
#include "Tile.h"
class Brick :
    public Tile
{
private:
public:
    bool floor = true;
    Brick(float x, float y, float size);
    ~Brick();
    void Draw() const override;
};

