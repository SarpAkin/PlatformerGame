#include "Vector2.h"

#include <math.h>


Vector2::Vector2(int x,int y)
{
    this->x = x;
    this->y = y;
}

float distance(Vector2 a,Vector2 b)
{
    return sqrtf((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}