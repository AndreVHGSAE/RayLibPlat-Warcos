#pragma once
#include <raylib.h>
class Tile
{
private:
	Vector2 position;
	float size;
	bool isActive = true;
	Rectangle boxCollider;
	float timer;
public:
	Tile(float x, float y, float size);
	~Tile();

	void Update(float DT);
	void Draw();
	void SetIsActive(bool active);
	Vector2 GetPosition();
	Rectangle getBoxCollider();

};

