#include "Game.h"
#include "PhysicsEngine.h"
//#include "Entities\Player.h"
bool Game::OnUserCreate()
{
    sAppName = "PlatformerGame";
    pivot = Vector2(ScreenWidth(),ScreenHeight()) / 2;


    Entities.push_back(new Player(Vector2(8,0),Vector2(1,1),*this));
    Entities[0]->setMass(1);

    Entities.push_back(new Entity(Vector2(10,3),Vector2(1.5f,1.5f)));
    Entities[1]->setMass(0.1f);


    //Triggers.push_back(new Collision_Trigger(Vector2(-3,5),Vector2(3,3)));

    player = dynamic_cast<Player*>(Entities[0]);
    player->drag = .8f;
    //std::cout << CameraCord->x;

    {
        Entity* e = new Entity(Vector2(0,10),Vector2(30,3));
        Entities.push_back(e);
        e->setMass(0);
        e->forces[0] = Vector2(0,0);
    }
    
    {
        Entity* e = new Entity(Vector2(0,0),Vector2(1,10));
        Entities.push_back(e);
        e->setMass(0);
        e->forces[0] = Vector2(0,0);
    }

    {
        Entity* e = new Entity(Vector2(29,0),Vector2(1,10));
        Entities.push_back(e);
        e->setMass(0);
        e->forces[0] = Vector2(0,0);
    }

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
    FillRect(2,2,(int)(player->StaminaBar * 40),5,olc::DARK_GREEN);
    for(Entity* e : Entities)
    {
        e->draw(*this);
    }
    if(isTriggersVisible)
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
