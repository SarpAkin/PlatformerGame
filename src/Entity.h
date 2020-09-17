#ifndef Entity_H
#define Entity_H

#include <array>
#include "Vector2.h"

class Game;
class Entity
{
public://variables
    Vector2 cord;
    Vector2 size;
    Vector2 velocity;
    std::array<Force,2> forces;//0 gravity 1 movement
    float weight;
public://functions
    inline Vector2 GetPivot()
    {
        return size / 2;
    }
    inline Vector2 GetMidPoint()
    {
        return cord + size / 2;
    }
    Entity(Vector2 c,Vector2 s);
    virtual void tick(Game& game,float elapsedTime);
    virtual void draw(Game& game);
};

#endif