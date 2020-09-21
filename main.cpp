#include <iostream>
#include "src\Game.h"

//for mingw: g++ -o game.exe  main.cpp src\*.cpp dependencies\*cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17

int main()
{
    #ifdef _Debug
    std::cout << "its debug\n";
    #endif
    Game game;
    if(game.Construct(512,512,1,1))
        game.Start();
}