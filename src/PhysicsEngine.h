#ifndef PhysicsEngine_H
#define PhysicsEngine_H

#include <vector>
#include "Entity.h"
#include "Vector2.h"

void simulateEntities(std::vector<Entity*>& Entities,float t);
bool isOverLapping(const AABB& a,const AABB& b);

#endif