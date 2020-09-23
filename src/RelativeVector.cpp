#include "RelativeVector.h"

#include "Entity.h"

RelativeVector::RelativeVector(Entity* r,Vector2 pivot)
{
    relativeEntity = r;
    this->pivot = pivot;
}
Vector2 RelativeVector::GetCord()
{
    if(relativeEntity)
        return relativeEntity->rcord.GetCord() + pivot;
    else
        return pivot;
}
void RelativeVector::SetCord(Vector2 cord)
{
    if(relativeEntity)
    {
        pivot = cord - relativeEntity->rcord.GetCord();
    }
    else
    {
        pivot = cord;
    }
}
void RelativeVector::setRelativeEntity(Entity* entity)
{
    Vector2 oldCord = GetCord();
    relativeEntity = entity;
    SetCord(oldCord);
}