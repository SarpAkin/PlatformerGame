#include "Player.h"

#include "..\Game.h"

void Player::tick(Game& game,float elapsedTime)
{
    std::cout << "velocity : " << velocity.x << " " << velocity.y << std::endl;
    //std::cout << "cord :" << boundry.cord.x << " " << boundry.cord.y << std::endl; 
    if(game.GetKey(olc::Key::W).bHeld)
        forces[1].y = -speed;
    else if(game.GetKey(olc::Key::S).bHeld)
        forces[1].y = speed;
    else
        forces[1].y = 0;

    if(game.GetKey(olc::Key::A).bHeld)
        forces[1].x = -speed;
    else if(game.GetKey(olc::Key::D).bHeld)
        forces[1].x = speed;
    else
        forces[1].x = 0;
}
void Player::draw(Game& game)
{
    Entity::draw(game);
}
Player::Player(Vector2 c,Vector2 s)
{
    boundry = AABB(c,s);
}