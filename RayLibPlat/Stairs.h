#pragma once
#include "Tile.h"
class Stairs :
    public Tile
{
private:

public:
    Stairs(float x, float y, float size);
    ~Stairs();
    void Draw() const override;
};


