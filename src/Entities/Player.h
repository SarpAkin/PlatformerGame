#include "..\Entity.h"
#include "..\Collision_Trigger.h"

class Player : public Entity
{
    private:
    Collision_Trigger* jumpTrigger;
    std::array<Collision_Trigger*,2> wallJumpTriggers;
    enum dir
    {
        left = 0,
        right = 1
    };
    bool doubleJump = false;
    public:
    float speed = 5.0f;
    float dashVelocity = 10.0f;
    float JumpVelocity = 10;
    float StaminaBar = 0.0f;
    public:
    Player(Vector2 c,Vector2 s,Game& game);
    void tick(Game& game,float elapsedTime) override;
    void draw(Game& game) override;
};