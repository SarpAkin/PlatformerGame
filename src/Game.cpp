#include "Game.h"

bool Game::OnUserCreate()
{
    sAppName = "PlatformerGame";
    Entities.push_back(new Entity(Vector2(0,0),Vector2(1,1)));
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    //ticking

    //physics

    //Rendering
    for(Entity* e : Entities)
    {
        e->draw(this[0]);
    }
    return true;
}

bool Game::OnUserDestroy()
{
    return true;
}

void Game::DrawEntity(olc::Sprite* s,Entity& e)
{

}
