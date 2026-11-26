#include "Character.h"

Character::Character(Vector2 pos, float s) 
	: position(pos), size(s)
{ 

}

Character::~Character()
{
}

void Character::Update()
{

}

void Character::Draw()
{
	DrawRectangle(position.x, position.y, size, size, DARKGREEN);
}

void Character::CollisionCheck(Tile& t)
{
	Rectangle player = { position.x,position.y, size, size };
	switch (t.GetType())
	{
	case TileType::Brick:
		if (CheckCollisionRecs(player, t.GetBoxCollider()))
		{
			position.y = t.GetPosition().y - 25;
			velocity.y = 0;
			isGrounded = true;
		}
		break;
	case TileType::Wall:
		break;
	case TileType::Stairs:
		break;
	}
}
