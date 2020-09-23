#include "Entity.h"

#include "Game.h"
#include <iostream>

void Entity::draw(Game& game)
{
    #if Debug
    //declarations
    Vector2 finalcord = (rcord.GetCord() - game.GetCamCord()) * game.TileSize;
    Vector2 finalsize = size * game.TileSize;
    //DrawLines
    game.DrawRect((int)finalcord.x,(int)finalcord.y,(int)finalsize.x,(int)finalsize.y,olc::RED);
    #endif
}
void Entity::tick(Game& game,float elapsedTime)
{
    //std::cout << "velocity : " << velocity.x << " " << velocity.y << std::endl;
}

Entity::Entity(Vector2 c,Vector2 s)
{
    rcord.SetCord(c),
    size = s;
}
Entity::Entity()
{
    
}