#include "Stairs.h"

Stairs::Stairs(float x, float y, float size) :
	Tile(x, y, size)
{
	SetType(TileType::Stairs);
}

Stairs::~Stairs()
{
}

void Stairs::Draw() const
{
	DrawRectangle(position.x, position.y, size, size, PURPLE);
}
