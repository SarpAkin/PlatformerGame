class Vector2
{
public:
    float x = 0;
    float y = 0;
    Vector2(int x,int y);
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
        return *this / distance(*this,zero);
    }
};

float distance(Vector2 a,Vector2 b);
const Vector2 zero = Vector2(0,0);