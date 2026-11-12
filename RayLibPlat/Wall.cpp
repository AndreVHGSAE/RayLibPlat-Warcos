#include "Wall.h"

Wall::Wall(float x, float y, float size) :
Tile(x, y, size)
{
	SetType(TileType::Wall);
}

Wall::~Wall(){}

void Wall::Draw() const
{
	DrawRectangle(position.x, position.y, size, size, GRAY);
	DrawRectangle(position.x+15, position.y+5, size-22, size-22, BLACK);
	DrawRectangle(position.x+5, position.y+15, size-22, size-22, BLACK);
}
