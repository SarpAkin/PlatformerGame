#include "PhysicsEngine.h"


void simulateEntities(std::vector<Entity*>& Entities)
{
    
}
bool isOverLapping(const Entity& a,const Entity& b)
{
    return a.cord.x < (b.cord.x + b.size.x) && (a.cord.x + a.size.x) > b.cord.x && a.cord.y < (b.cord.y + b.size.y) && (a.cord.y + a.size.y) > b.cord.y;
}