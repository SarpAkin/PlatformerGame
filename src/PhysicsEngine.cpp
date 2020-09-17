#include "PhysicsEngine.h"

inline void simulateEntity(Entity* e,float deltaT)
{
    Vector2 totalStaticForce = e->forces[0] + e->forces[1];
    e->velocity = (totalStaticForce - e->velocity) * deltaT * e->inversemass + e->velocity; 
    e->cord = e->cord + e->velocity * deltaT;
}
void simulateEntities(std::vector<Entity*>& Entities,float deltaT)
{
    for(Entity* e : Entities)
    {
        simulateEntity(e,deltaT);
    }
}
bool isOverLapping(const Entity& a,const Entity& b)
{
    return a.cord.x < (b.cord.x + b.size.x) && (a.cord.x + a.size.x) > b.cord.x && a.cord.y < (b.cord.y + b.size.y) && (a.cord.y + a.size.y) > b.cord.y;
}