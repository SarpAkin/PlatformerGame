
#include "Player.h"

#include "..\Game.h"

void Player::tick(Game& game,float elapsedTime)
{
    //std::cout << "velocity : " << velocity.x << " " << velocity.y << std::endl;
    //std::cout << "cord :" << boundry.cord.x << " " << boundry.cord.y << std::endl;
    bool isGrounded = jumpTrigger->CollidingEntities.size() > 0;
    StaminaBar += elapsedTime;
    if(StaminaBar > 1)
        StaminaBar = 1;

    if(game.GetKey(olc::Key::SPACE).bPressed)
    {
        if(wallJumpTriggers[left]->CollidingEntities.size() > 0)
        {
            velocity = Vector2(JumpVelocity * 0.75f,JumpVelocity * -0.4f);
            goto postJump;
        }
        else if(wallJumpTriggers[right]->CollidingEntities.size() > 0)
        {
            velocity = Vector2(JumpVelocity * -0.75f,JumpVelocity * -0.4f);
            goto postJump;
        }
    }
    
    if(isGrounded)
    {
        doubleJump = true;
        if(game.GetKey(olc::Key::SPACE).bPressed)
        {
            velocity.y = -JumpVelocity;
        }
    }
    else
    {
        if(game.GetKey(olc::Key::SPACE).bPressed && doubleJump)
        {
            doubleJump = false;
            velocity.y = -JumpVelocity * 0.75f;
        }
    }

    postJump:

    if(game.GetKey(olc::Key::SHIFT).bPressed && StaminaBar == 1)
    {
        if(game.GetKey(olc::Key::A).bHeld)
        {
            velocity.x = -dashVelocity; 
            StaminaBar = 0;
        }
        else if(game.GetKey(olc::Key::D).bHeld)
        {
            velocity.x = dashVelocity;
            StaminaBar = 0;
        }
    }

    if(game.GetKey(olc::Key::A).bHeld)
        forces[1].x = -speed;
    else if(game.GetKey(olc::Key::D).bHeld)
        forces[1].x = speed;
    else
        forces[1].x = 0;
    
    //jumpTrigger->cord = cord + Vector2(0,size.y + 0.1f); 
}
void Player::draw(Game& game)
{
    Entity::draw(game);
}
Player::Player(Vector2 c,Vector2 s,Game& game)
{
    rcord.SetCord(c);
    size = s;
    jumpTrigger = new Collision_Trigger(RelativeVector(this,Vector2(0.1f,size.y)),Vector2(size.x - 0.2f,0.1f));
    wallJumpTriggers[left] = new Collision_Trigger(RelativeVector(this,Vector2(-0.1f,0)),Vector2(0.1f,size.y));
    wallJumpTriggers[right] = new Collision_Trigger(RelativeVector(this,Vector2(size.x,0)),Vector2(0.1f,size.y));
    game.Triggers.push_back(jumpTrigger);
    for(auto a : wallJumpTriggers)
        game.Triggers.push_back(a);
}
