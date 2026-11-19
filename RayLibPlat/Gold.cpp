#include "Gold.h"

Gold::Gold(float x, float y, float size)
{
	position.x = x;
	position.y = y;
	this->size = size;

	boxCollider = { position.x, position.y,size, size};
}


Gold::~Gold()
{
}

void Gold::Draw()
{
	DrawRectangle(position.x, position.y, size, size, YELLOW);
}
void Gold :: Update()
{

}
