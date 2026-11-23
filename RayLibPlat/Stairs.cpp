#include "Stairs.h"

Stairs::Stairs(float x, float y, float size) :
	Tile(x, y, size)
{
	SetType(TileType::Stairs);
}

Stairs::~Stairs(){}

void Stairs::Draw() const
{
	DrawRectangle(position.x, position.y, size, size, YELLOW);
	DrawRectangle(position.x+3, position.y, size-6, size-5, DARKBLUE);
	DrawRectangle(position.x+3, position.y+8, size-6, size-20, YELLOW);
}
