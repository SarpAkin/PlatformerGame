#include "Game.h"
#include "PhysicsEngine.h"
#include "Entities\Player.h"
bool Game::OnUserCreate()
{
    sAppName = "PlatformerGame";
    Entities.push_back(new Player(Vector2(0,0),Vector2(1,1)));
    Entities[0]->setMass(.5f);

    Entities.push_back(new Entity(Vector2(10,10),Vector2(3,3)));
    Entities[1]->setMass(0);
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    //ticking
    for(Entity* e : Entities)
    {
        e->tick(*this,fElapsedTime);
    }
    //physics
    simulateEntities(Entities,fElapsedTime);
    //Rendering
    FillRect(0,0,ScreenWidth(),ScreenWidth(),olc::BLACK);
    for(Entity* e : Entities)
    {
        e->draw(*this);
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
