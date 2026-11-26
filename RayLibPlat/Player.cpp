#include "Player.h"

Player::Player(float x, float y, float size)
:Character({x, y}, size)
{


}

Player::~Player()
{
}

void Player::PlayerCollisionCheck(Brick& b)
{
	Rectangle player{ position.x +10, position.y+ 10,size,size };
	if (IsKeyDown(KEY_Z))CheckCollisionRecs(player, b.GetBoxCollider());
	{
		b.floor = false;

	}
}

void Player::Update()
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

void Player:: Draw()
{
	DrawRectangle(position.x, position.y, size, size, DARKPURPLE);
}

