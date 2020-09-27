#include "Game.h"

#include <fstream>
#include <string>

#include "PhysicsEngine.h"
#include "ClassParser.h"

bool Game::OnUserCreate()
{
    sAppName = "PlatformerGame";
    pivot = Vector2(ScreenWidth(),ScreenHeight()) / 2;


    Entities.push_back(new Player(Vector2(8,0),Vector2(1,1),*this));
    Entities[0]->setMass(1);

    std::ifstream ifs = std::ifstream("Map.txt");
    if(ifs.is_open())
    {
        std::string content = std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
        int size = content.length() / sizeof(AABB);
        for(int i = 0;i < size;i++)
        {
            std::array<char,sizeof(AABB)> arr;
            int string_pos = i * sizeof(AABB);
            for(int j = 0;j < sizeof(AABB);j++)
            {
                arr[j] = content[string_pos + j];
            }
            AABB wall = ParseToClass<AABB>(arr);
            Entity* e = new Entity(wall.cord,wall.size);
            Entities.push_back(e);
            e->setMass(0);
            e->forces[0] = Vector2(0,0);
        }
    }
    player = dynamic_cast<Player*>(Entities[0]);
    player->drag = .8f;

    


    //Triggers.push_back(new Collision_Trigger(Vector2(-3,5),Vector2(3,3)));

    //std::cout << CameraCord->x;

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
