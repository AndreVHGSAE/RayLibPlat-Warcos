#include "Tile.h"

Tile::Tile(float x, float y, float size)
{
    boxCollider = { x,y,size,size };
    this->position.x = x;
    this->position.y = y;
    this->size = size;
    this->timer = 0;
}

Tile::~Tile()
{
}

void Tile::Update(float DT)
{
}

void Tile::Draw()
{
    DrawRectangle(position.x, position.y, size, size, BROWN);
}

void Tile::SetIsActive(bool activate)
{
}

Vector2 Tile::GetPosition()
{
    return position;
}

Rectangle Tile::getBoxCollider()
{
    return boxCollider;
}