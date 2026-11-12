#pragma once
#include "Wall.h"
Wall::Wall(float x, float y, float size) :
	Tile(x, y, size)
{
	SetType(TileType::Wall);
}

Wall::~Wall()
{
}

void Wall::Draw() const
{
	DrawRectangle(position.x, position.y, size, size, ORANGE);

}
