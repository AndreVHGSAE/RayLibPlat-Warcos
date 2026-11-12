#include "Character.h"
#include <iostream>

Character::Character(Vector2 pos, float s)
    : position(pos), size(s)
{

}

Character::~Character()
{
}

void Character::Update()
{

    if (IsKeyDown(KEY_A))
    {
        velocity.x = -moveSpeed;
    }
    else if (IsKeyReleased(KEY_A))
    {
        velocity.x = 0;
    }
    if (IsKeyDown(KEY_D))
    {
        velocity.x = moveSpeed;
    }
    else if (IsKeyReleased(KEY_D))
    {
        velocity.x = 0;
    }
    if (isOnStairs == true)
    {
        if (IsKeyDown(KEY_W))
        {
            velocity.y = -moveSpeed;
        }
        else if (IsKeyReleased(KEY_W))
        {
            velocity.y = 0;
        }
        if (IsKeyDown(KEY_S))
        {
            velocity.y = moveSpeed;
        }
        else if (IsKeyReleased(KEY_S))
        {
            velocity.y = 0;
        }
    }
    else
    {
        velocity.y += gravity;
    }
    if (velocity.y >= 0 || ((IsKeyDown(KEY_W) && (IsKeyDown(KEY_D) || IsKeyDown(KEY_A)))))
    {
        isOnStairs = false;
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
    Rectangle collider = { position.x,position.y,size,size };
    switch (t.GetType())
    {
    case TileType::Brick:
        if (t.GetIsActive())
        {
            if (CheckCollisionRecs(collider, t.getBoxCollider()))
            {
                position.y = t.GetPosition().y - 25;
                velocity.y = 0;
                isGrounded = true;
                //if (velocity.x < 0)
                //{
                //    position.x += 5;
                //}
                //else if (velocity.x > 0)
                //{
                //    position.x -= 5;
                //}
            }
        }
        break;
    case TileType::Wall:
        if (t.GetIsActive())
        {
            if (CheckCollisionRecs(collider, t.getBoxCollider()))
            {
                position.y = t.GetPosition().y - 25;
                velocity.y = 0;
                isGrounded = true;
                if (velocity.x < 0)
                {
                    position.x += 5;
                }
                else if (velocity.x > 0)
                {
                    position.x -= 5;
                }
            }
        }
        break;
    case TileType::Stairs:
        if (t.GetIsActive())
        {
            if (CheckCollisionRecs(collider, t.getBoxCollider()))
            {
                isOnStairs = true;
            }
        }
        break;

    }

}

bool Character::isAlive()
{
    return false;
}