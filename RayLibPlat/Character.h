#pragma once
#include "raylib.h"
#include "tile.h"
class Character
{
private:
	Vector2 position;
	Vector3 velocity = { 0, 0 };
	float gravity = 0.8f;
	const float moveSpeed = 5.0f;
	const float jumpForce = -2;
	float size;
	bool isGrounded = false;
	bool isOnStairs = false;
public:
	Character(Vector2 pos, float s);
	~Character();

	void Update();
	void Draw();
	void Collision(Tile & t);

	bool isAlive();
};

