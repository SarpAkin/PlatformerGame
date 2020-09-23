#include <iostream>
#include "src\Game.h"

 int main()
{
    Game game;
    Vector2 v;
    if(game.Construct(1024,1024,1,1))
        game.Start();
}