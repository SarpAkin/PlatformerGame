#ifndef PhysicsEngine_H
#define PhysicsEngine_H

#include <vector>
#include "Entity.h"
#include "Vector2.h"
#include "Collision_Trigger.h"

void simulateEntities(std::vector<Entity*>& Entities,std::vector<Collision_Trigger*> triggers,float t);
bool isOverLapping(Entity& a,Entity& b);
bool isOverLapping(Entity& a,const AABB& b);
bool isOverLapping(const AABB& a,const AABB& b);
#endif