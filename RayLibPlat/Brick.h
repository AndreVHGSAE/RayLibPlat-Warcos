#pragma once
#include "Tile.h"
class Brick :
    public Tile
{
private:
public:
    Brick(float x, float y, float size);
    ~Brick();
    void Draw() const override;


};

