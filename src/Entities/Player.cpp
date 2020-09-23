#include "Player.h"

#include "..\Game.h"

void Player::tick(Game& game,float elapsedTime)
{
    //std::cout << "velocity : " << velocity.x << " " << velocity.y << std::endl;
    //std::cout << "cord :" << boundry.cord.x << " " << boundry.cord.y << std::endl;
    if(game.GetKey(olc::Key::SPACE).bPressed)
    {
        if(jumpTrigger->CollidingEntities.size() > 0)
            velocity.y -= 10;
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
    std::cout <<"this " << this << std::endl;
    jumpTrigger = new Collision_Trigger(RelativeVector(this,Vector2(0,size.y)),size);
    game.Triggers.push_back(jumpTrigger);
    std::cout << game.Triggers.size();
}