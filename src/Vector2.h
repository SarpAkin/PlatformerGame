#ifndef Vector2_H
#define Vector2_H

class Vector2;

float distance(Vector2 a,Vector2 b);

class Vector2
{
public:
    float x = 0;
    float y = 0;
    Vector2(float x,float y);
    Vector2();
    inline Vector2 operator + (Vector2 v2)
    {
        return Vector2(this->x + v2.x,this->y + v2.y);
    }
    inline Vector2 operator - (Vector2 v2)
    {
        return Vector2(this->x - v2.x,this->y - v2.y);
    }
    inline Vector2 operator * (float f)
    {
        return Vector2(this->x * f,this->y * f);
    }
    inline Vector2 operator / (float f)
    {
        return Vector2(this->x / f,this->y / f);
    }
    inline Vector2 normalized()
    {
        return *this / distance(*this,Vector2(0,0));
    }
};
struct Force
{
    Vector2 force;
    Vector2 MaxSpeed;
    Force(Vector2 f,Vector2 m)
    {
        force = f;
        MaxSpeed = m;
    }
    Force()
    {
        
    }
};
#endif