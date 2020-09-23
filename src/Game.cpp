#include "Game.h"
#include "PhysicsEngine.h"
#include "Entities\Player.h"
bool Game::OnUserCreate()
{
    sAppName = "PlatformerGame";
    pivot = Vector2(ScreenWidth(),ScreenHeight()) / 2;


    Entities.push_back(new Player(Vector2(0,0),Vector2(1,1),*this));
    Entities[0]->setMass(1);


    Triggers.push_back(new Collision_Trigger(Vector2(-3,5),Vector2(3,3)));

    player = Entities[0];
    player->drag = .8f;
    //std::cout << CameraCord->x;
    Entities.push_back(new Entity(Vector2(-5,10),Vector2(30,3)));
    Entities[1]->setMass(0);
    Entities[1]->forces[0] = Vector2(0,0);

    Entities.push_back(new Entity(Vector2(10,3),Vector2(1.5f,1.5f)));
    Entities[2]->setMass(0.1f);

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
    simulateEntities(Entities,Triggers,fElapsedTime);
    //Rendering
    CameraCord = player->GetMidPoint();
    FillRect(0,0,ScreenWidth(),ScreenWidth(),olc::BLACK);
    DrawRect(0,0,5,5,olc::GREY);
    for(Entity* e : Entities)
    {
        e->draw(*this);
    }
    for(Collision_Trigger* t : Triggers)
    {
        Vector2 finalcord = (t->rcord.GetCord() - GetCamCord()) * TileSize;
        //std::cout << t->rcord.GetCord().ToString() << std::endl;
        Vector2 finalsize = t->size * TileSize;

        if(t->CollidingEntities.size() == 0)
            DrawRect((int)finalcord.x,(int)finalcord.y,(int)finalsize.x,(int)finalsize.y,olc::GREEN);
        else
            DrawRect((int)finalcord.x,(int)finalcord.y,(int)finalsize.x,(int)finalsize.y,olc::YELLOW);
        
    }
    return true;
}

bool Game::OnUserDestroy()
{
    for(Entity* e : Entities)
    {
        delete e;
    }
    return true;
}

void Game::DrawEntity(olc::Sprite* s,Entity& e)
{

}
