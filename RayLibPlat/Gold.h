#pragma once
#include <raylib.h>
class Gold
{
private:
	Vector2 position;
	float size;
	Rectangle goldCollider;
	bool isActive = true;
public:
	Gold(float x, float y, float size);
	~Gold();

	void Draw();
	void Update();
	Rectangle GetGoldCollider();

	bool GetIsActive();
	void SetIsActive(bool value);
};

