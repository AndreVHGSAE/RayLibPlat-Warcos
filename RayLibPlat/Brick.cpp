#include "Brick.h"
Brick::Brick(float x, float y, float size):
	Tile(x,y,size)
{
	SetType(TileType::Brick);
}
Brick::~Brick() {}

void Brick::Draw() const
{
	DrawRectangle(position.x, position.y, size, size, RED);
}
