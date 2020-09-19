#include "PhysicsEngine.h"
#include "Vector2.h"
#include <iostream>

inline void simulateColidingEntity(Entity* current,Entity* other)
{
    Vector2 cordDiff = current->boundry.GetCenterPoint() - other->boundry.GetCenterPoint();
    Vector2 sizeSum = (current->boundry.size + other->boundry.size) / 2;
    Vector2 AbsCollisionDepth = sizeSum - Vector2(std::abs(cordDiff.x),std::abs(cordDiff.y));

    if(AbsCollisionDepth.x > AbsCollisionDepth.y)
        if(cordDiff.y > 0)
            current->boundry.cord.y += AbsCollisionDepth.y;
        else
            current->boundry.cord.y -= AbsCollisionDepth.y;
    else
        if(cordDiff.x > 0)
            current->boundry.cord.x += AbsCollisionDepth.x;
        else
            current->boundry.cord.x -= AbsCollisionDepth.x;

}
void simulateEntities(std::vector<Entity*>& Entities,float deltaT)
{
    if(deltaT == 0)//if delta is 0 it causes bugs
        return;
    for(int i = 0;i < Entities.size();i++)
    {
        Vector2 totalStaticForce = Entities[i]->forces[0] + Entities[i]->forces[1];
        Entities[i]->velocity += (totalStaticForce - Entities[i]->velocity) * deltaT * Entities[i]->inversemass;
        Vector2 startingCord = Entities[i]->boundry.cord;
        Entities[i]->boundry.cord += Entities[i]->velocity * deltaT;
        
        for(int j = 0;j < i;j++)
        {
            if(isOverLapping(Entities[i]->boundry,Entities[j]->boundry))
            {
                simulateColidingEntity(Entities[i],Entities[j]);
            }
        }
        for(int j = i + 1;j < Entities.size();j++)
        {
            if(isOverLapping(Entities[i]->boundry,Entities[j]->boundry))
            {
                simulateColidingEntity(Entities[i],Entities[j]);
            }
        }
        Entities[i]->velocity = (Entities[i]->boundry.cord - startingCord) / deltaT;
    }
}
bool isOverLapping(const AABB& a,const AABB& b)
{
    return a.cord.x < (b.cord.x + b.size.x) && (a.cord.x + a.size.x) > b.cord.x && a.cord.y < (b.cord.y + b.size.y) && (a.cord.y + a.size.y) > b.cord.y;
}