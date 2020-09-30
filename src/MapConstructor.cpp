#include "MapConstructor.h"

#include <fstream>
#include <string>

#include "ClassParser.h"
#include "PhysicsEngine.h"

#define Map MapConstructor

bool Map::OnUserCreate()
{
    pivot = Vector2(ScreenWidth(),ScreenHeight()) / 2;

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
            Walls.push_back(wall);
        }
    }
    return true;
}

bool Map::OnUserUpdate(float fElapsedTime)
{
    FillRect(0,0,ScreenWidth(),ScreenWidth(),olc::BLACK);
    if(GetMouse(0).bPressed)
    {
        startPoint = ScreenCordToLocal(GetMouseX(),GetMouseY());
        isDrawing = true;
    }

    if(GetMouse(0).bReleased && isDrawing)
    {
        AABB wall = AABB(startPoint,ScreenCordToLocal(GetMouseX(),GetMouseY()) - startPoint);
        wall.FixBoundry();
        Walls.push_back(wall);
        isDrawing = false;
    }

    if(GetMouse(1).bPressed)
    {
        EstartPoint = ScreenCordToLocal(GetMouseX(),GetMouseY());
        isEreasing = true;
    }

    if(GetMouse(1).bReleased && isEreasing)
    {
        AABB EraseArea = AABB(EstartPoint,ScreenCordToLocal(GetMouseX(),GetMouseY()) - EstartPoint);
        EraseArea.FixBoundry();
        for(auto it = Walls.begin();it < Walls.end();it++)
        {
            if(isOverLapping(*it,EraseArea))
            {
                Walls.erase(it);
                it--;
            }
        }
        isEreasing = false;
    }

    for(auto wall : Walls)
    {
        Vector2 finalsize = wall.size * TileSize;
        DrawRect(LocalCordToScreen(wall.cord),olc::vi2d((int)finalsize.x,(int)finalsize.y),olc::RED);
    }

    if(isDrawing)
    {
        Vector2 finalsize = (ScreenCordToLocal(GetMouseX(),GetMouseY()) - startPoint) * TileSize;
        DrawRect(LocalCordToScreen(startPoint),olc::vi2d((int)finalsize.x,(int)finalsize.y),olc::RED);
    }

    if(isEreasing)
    {
        Vector2 finalsize = (ScreenCordToLocal(GetMouseX(),GetMouseY()) - EstartPoint) * TileSize;
        DrawRect(LocalCordToScreen(EstartPoint),olc::vi2d((int)finalsize.x,(int)finalsize.y),olc::BLUE);
    }

    FillRect(LocalCordToScreen(Vector2(0,0)),olc::vi2d((int)TileSize,(int)TileSize),olc::GREEN);

    TileSize += GetMouseWheel() * fElapsedTime;

    if(TileSize < MinTileSize)
        TileSize = MinTileSize;

    if(TileSize > MaxTileSize)
        TileSize = MaxTileSize;

    if(GetKey(olc::Key::A).bHeld)
        CameraCord.x += (256 / TileSize) * -fElapsedTime;
    else if(GetKey(olc::Key::D).bHeld)
        CameraCord.x += (256 / TileSize) * fElapsedTime;

    if(GetKey(olc::Key::W).bHeld)
        CameraCord.y += (256 / TileSize) * -fElapsedTime;
    else if(GetKey(olc::Key::S).bHeld)
        CameraCord.y += (256 / TileSize) * fElapsedTime;

    return true;
}

bool Map::OnUserDestroy()
{
    std::ofstream of = std::ofstream("Map.txt");
    if(of.is_open())
    {
        of.flush();
        for(AABB& Wall : Walls)
        {
            auto arr = ParseToStream(Wall);
            for(char c : arr)
            {
                of << c;
            }
        }
    }
    of.close();
    Game::OnUserDestroy();
    return true;
}