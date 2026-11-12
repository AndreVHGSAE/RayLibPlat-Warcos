#pragma once
#include <raylib.h>

enum class TileType {
	Brick, //
	Wall, //
	Stairs //
};
class Tile
{
private:

protected:
	TileType type;
	Vector2 position;
	float size;
	bool isActive = true;
	Rectangle boxCollider;
	void SetType(TileType t) { type = t; }
public:
	Tile(float x, float y, float size);
	~Tile();

	void Update(float DT);
	virtual void Draw() const = 0;

	TileType GetType() { return type;  }
	void SetIsActive(bool active) { isActive = active; }
	bool GetIsActive() { return isActive; }
	Rectangle GetBoxCollider() { return boxCollider; }
	Vector2 GetPosition() { return position; };

};

