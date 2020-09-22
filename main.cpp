#include <iostream>
#include "src\Game.h"


int main()
{
    Game game;
    if(game.Construct(512,512,1,1))
        game.Start();
}
