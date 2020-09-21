#ifndef Entity_H
#define Entity_H

#include <array>
#include "Vector2.h"

#define Debug 1

class Game;
class Entity
{
    public://variables
    AABB boundry;
    Vector2 velocity;
    Vector2 acceleration;
    std::array<Vector2,2> forces;//0 gravity 1 movement
    float inversemass = 0;
    float bouncieness = 1.0f;
    float drag = 1.0f;
    private:
    float mass = 1;
    public://functions
    inline Vector2 GetPivot()
    {
        return boundry.size / 2;
    }
    inline Vector2 GetMidPoint()
    {
        return boundry.cord + boundry.size / 2;
    }
    inline void setMass(float m)
    {
        mass = m;
        if(m == 0)
            inversemass = 0;
        else
            inversemass = 1 / m;
    }
    inline float getMass()
    {
        return mass;
    }
    Entity(Vector2 c,Vector2 s);
    Entity();
    virtual void tick(Game& game,float elapsedTime);
    virtual void draw(Game& game);
};

#endif