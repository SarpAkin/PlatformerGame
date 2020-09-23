#ifndef Entity_H
#define Entity_H

#include <array>
#include "Vector2.h"

#define Debug 1

class Game;

#include "RelativeVector.h"
class Entity
{
    public://variables
    //AABB boundry;
    //Vector2 cord;
    RelativeVector rcord = RelativeVector(NULL,Vector2(0,0));
    Vector2 size;
    Vector2 velocity;
    Vector2 acceleration;
    std::array<Vector2,2> forces = {Vector2(0,5),Vector2(0,0)};
    float inversemass = 0;
    float bouncieness = 1.0f;
    float drag = 0.8f;
    private:
    float mass = 1;
    public://functions
    inline Vector2 GetPivot()
    {
        return size / 2;
    }
    inline Vector2 GetMidPoint()
    {
        return rcord.GetCord() + size / 2;
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