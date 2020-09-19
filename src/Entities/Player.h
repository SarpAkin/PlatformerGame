#include "..\Entity.h"

class Player : public Entity
{
    public:
    float speed = 2.0f;
    public:
    Player(Vector2 c,Vector2 s);
    void tick(Game& game,float elapsedTime) override;
    void draw(Game& game) override;
};