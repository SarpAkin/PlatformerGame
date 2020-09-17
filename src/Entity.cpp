#include "Entity.h"
#if 1
#include "Game.h"
void Entity::draw(Game& game)
{
    #if Debug
    //declarations
    Vector2 finalcord = (cord - *game.CameraCord) / game.TileSize;
    Vector2 finalsize = size / game.TileSize;
    //DrawLines
    game.DrawRect((int)finalcord.x,(int)finalcord.y,(int)finalsize.x,(int)finalsize.y,olc::RED);
    #endif
}
void Entity::tick(Game& game,float elapsedTime)
{
    //do nothing
}
#else
void Entity::draw(Game& game)
{
    //do nothing
}
void Entity::tick(Game& game,float elapsedTime)
{
    //do nothing
}
#endif
Entity::Entity(Vector2 c,Vector2 s)
{
    cord = c;
    size = s;
}