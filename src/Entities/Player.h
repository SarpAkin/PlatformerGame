#include "..\Entity.h"
#include "..\Collision_Trigger.h"

class Player : public Entity
{
    private:
    Collision_Trigger* jumpTrigger;
    public:
    float speed = 4.0f;
    public:
    Player(Vector2 c,Vector2 s,Game& game);
    void tick(Game& game,float elapsedTime) override;
    void draw(Game& game) override;
};