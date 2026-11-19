#pragma once
#include<raylib.h>
class Gold
{
public:
	Vector2 position;
	Rectangle boxCollider;
	float size;
	bool isActive = true;

	Gold(float x, float y, float size);
	~Gold();
	void Draw();
	void Update();
private:

};

