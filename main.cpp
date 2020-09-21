#include <iostream>
#include "src\Game.h"

int main()
{
    #ifdef _Debug
    std::cout << "its debug\n";
    #endif
    Game game;
    if(game.Construct(512,512,1,1))
        game.Start();
}
