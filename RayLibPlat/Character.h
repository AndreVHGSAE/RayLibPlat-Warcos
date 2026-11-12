#pragma once
#include "raylib.h"
#include "Tile.h"

class Character
{
private:
	Vector2 position;
	Vector2 velocity = { 0,0 };
	float gravity = 0.8;
	const float moveSpeed = 5.0f;
	const float jumpForce = -2;
	float size;
	bool isGrounded = false;
public:
	Character(Vector2 pos, float s);
	~Character();

	void Update();
	void Draw();
	void CollisionCheck(Tile & t);
};

