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
	velocity.y += gravity;
	if (IsKeyDown(KEY_A))
	{
		velocity.x = -moveSpeed;
	}
	else if (IsKeyReleased(KEY_A))
	{
		velocity.x = 0;
	}
	velocity.y += gravity;
	if (IsKeyDown(KEY_D))
	{
		velocity.x = moveSpeed;
	}
	else if (IsKeyReleased(KEY_D))
	{
		velocity.x = 0;
	}
	position.x += velocity.x;
	position.y += velocity.y;
}

void Character::Draw()
{
	DrawRectangle(position.x, position.y, size, size, BLUE);
}

void Character::Collision(Tile& t)
{
	Rectangle collider = { position.x,position.y, size, size };
	if (CheckCollisionRecs(collider, t.getBoxCollider()))
	{
		position.y = t.GetPosition().y - 25;
		velocity.y = 0;
		isGrounded = true;
	}
}
