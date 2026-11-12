#include "Brick.h"
Brick::Brick(float x, float y, float size) :
	Tile(x, y, size)
{
	SetType(TileType::Brick);
}
Brick::~Brick() {}

void Brick::Draw() const
{
	DrawRectangle(position.x, position.y, size, size, RED);
	DrawRectangle(position.x, position.y, size, size-23, BROWN);
	DrawRectangle(position.x, position.y+12, size, size-23, BROWN);
	DrawRectangle(position.x, position.y, size-23, size-12, BROWN);
	DrawRectangle(position.x+12, position.y+12, size-23, size-12, BROWN);
}