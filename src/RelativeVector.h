#ifndef RelativeVector_H
#define RelativeVector_H

#include "Vector2.h"
class Entity;
class RelativeVector
{
    private:
    Entity* relativeEntity = NULL;
    public:
    Vector2 pivot;
    public:
    RelativeVector(Entity* r,Vector2 pivot);
    Vector2 GetCord();
    void SetCord(Vector2 cord);
    void setRelativeEntity(Entity* Entity);//Set NULL to set to Nothing
};


#endif