#ifndef Collision_Trigger_H
#define Collision_Trigger_H

#include "Entity.h"
#include <vector>

class Collision_Trigger
{
    public:
    std::vector<Entity*> CollidingEntities;
    //Vector2 cord;
    RelativeVector rcord = RelativeVector(NULL,Vector2(0,0));
    Vector2 size;
    protected:
    virtual void OnCollisionEnter(Entity* e);
    virtual void OnCollisionExit(Entity* e);
    public:
    Collision_Trigger(Vector2 cord,Vector2 size);
    Collision_Trigger(RelativeVector rcord,Vector2 size);
    void CheckEntity(Entity* e);
};

#endif