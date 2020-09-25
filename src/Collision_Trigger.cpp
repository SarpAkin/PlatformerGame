#include "Collision_Trigger.h"

#include "PhysicsEngine.h"
#include <iostream>
#define trigger Collision_Trigger

void trigger::CheckEntity(Entity* e)
{
    //std::cout << e->cord.ToString() + " " + e->size.ToString() + " " + cord.ToString() + " " + size.ToString() << std::endl; 
    if(isOverLapping(*e,AABB(rcord.GetCord(),size)))
    {
        for(Entity* o : CollidingEntities) 
        {
            if(e == o)
                return;
        }
        CollidingEntities.push_back(e);
        OnCollisionEnter(e);
    }
    else
    {
        for(auto o = CollidingEntities.begin(); o < CollidingEntities.end();o++)
        {
            if(e == *o)
            {
                CollidingEntities.erase(o);
                OnCollisionExit(e);
                return;
            }
        }
    }
}

trigger::Collision_Trigger(Vector2 cord_,Vector2 size_)
{
    rcord.SetCord(cord_);
    size = size_;
}
trigger::Collision_Trigger(RelativeVector rcord_,Vector2 size_)
{
    rcord = rcord_;
    size = size_;
}

void trigger::OnCollisionEnter(Entity* e)
{
    //do nothing
}

void trigger::OnCollisionExit(Entity* e)
{
    //do nothing
}