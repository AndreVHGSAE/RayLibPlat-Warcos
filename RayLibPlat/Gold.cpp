#include "Gold.h"

Gold::Gold(float x, float y, float size)
{
	this->position.x = x;
	this->position.y = y;
	this->size = size;
	goldCollider = { x,y,size,size };
}

Gold::~Gold()
{
}

void Gold::Draw()
{
	if (isActive == true)
		DrawRectangle(position.x, position.y, size, size, YELLOW);
}

void Gold::Update()
{
}

Rectangle Gold::GetGoldCollider()
{
	return goldCollider;
}

bool Gold::GetIsActive()
{
	return isActive;
}

void Gold::SetIsActive(bool value)
{
	this->isActive = value;
}