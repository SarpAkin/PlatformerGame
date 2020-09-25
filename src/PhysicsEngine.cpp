#include "PhysicsEngine.h"
#include "Vector2.h"
#include <iostream>

inline void simulateColidingEntity(Entity* current,Entity* other,float deltaT)
{
    Vector2 cordDiff = current->GetMidPoint() - other->GetMidPoint();
    Vector2 sizeSum = (current->size + other->size) / 2;
    Vector2 AbsCollisionDepth = sizeSum - Vector2(std::abs(cordDiff.x),std::abs(cordDiff.y));

    Vector2 totalDisplacement;
    if(AbsCollisionDepth.x > AbsCollisionDepth.y)
        if(cordDiff.y > 0)
            totalDisplacement.y = AbsCollisionDepth.y;
        else
            totalDisplacement.y = -AbsCollisionDepth.y; 
    else
        if(cordDiff.x > 0)
            totalDisplacement.x = AbsCollisionDepth.x;
        else
            totalDisplacement.x = -AbsCollisionDepth.x;

    totalDisplacement += totalDisplacement * (((current->bouncieness + other->bouncieness) / 2 - 1) / deltaT);

    if(other->inversemass == 0)
        current->rcord.pivot += totalDisplacement;
    else if(current->inversemass == 0)
        other->rcord.pivot += totalDisplacement;
    else
    {
        float totalmass = current->getMass() + other->getMass();
        current->rcord.pivot += totalDisplacement * (other->getMass() / totalmass);
        other->rcord.pivot += totalDisplacement * (current->getMass() / totalmass);
    }
}

void simulateEntities(std::vector<Entity*>& Entities,std::vector<Collision_Trigger*> triggers,float deltaT)
{
    if(deltaT == 0)//if delta is 0 it causes bugs
        return;
    for(int i = 0;i < Entities.size();i++)
    {
        Entity* current = Entities[i];
        Vector2 startingCord = current->rcord.GetCord();
        if(current->inversemass != 0)
        {
            Vector2 totalStaticForce = current->forces[0] + current->forces[1];
            Vector2 acceleration = current->velocity * -current->drag + totalStaticForce;
            current->velocity += acceleration * deltaT;
            current->rcord.pivot += current->velocity * deltaT;
            
            for (int j = 0; j < i;j++)
            {
                if(isOverLapping(*current,*Entities[j]))
                {
                    simulateColidingEntity(current,Entities[j],deltaT);
                }
            }
            for(int j = i + 1;j < Entities.size();j++)
            {
                if(isOverLapping(*current,*Entities[j]))
                {
                    simulateColidingEntity(current,Entities[j],deltaT);
                }
            }
            current->velocity = (current->rcord.GetCord() - startingCord) / deltaT;

            if(std::abs(current->velocity.x) < 0.1f && std::abs(totalStaticForce.x) < 0.1f)
                current->velocity.x = 0;
            if(std::abs(current->velocity.y) < 0.1f && std::abs(totalStaticForce.y) < 0.1f)
                current->velocity.y = 0;
        }

        AABB startingBoundry = AABB(startingCord,current->size);
        for(auto trigger : triggers)
        {
            //if(isOverLapping(startingBoundry,AABB(trigger->cord,trigger->size)))
                trigger->CheckEntity(current);
        }
    }
}
bool isOverLapping(Entity& a,Entity& b)
{
    return isOverLapping(AABB(a.rcord.GetCord(),a.size),AABB(b.rcord.GetCord(),b.size));
}
bool isOverLapping(Entity& a,const AABB& b)
{
    return isOverLapping(AABB(a.rcord.GetCord(),a.size),b);
}
bool isOverLapping(const AABB& a,const AABB& b)
{
    return a.cord.x < (b.cord.x + b.size.x) && (a.cord.x + a.size.x) > b.cord.x && a.cord.y < (b.cord.y + b.size.y) && (a.cord.y + a.size.y) > b.cord.y;
}