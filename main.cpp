#include <iostream>
#include <string>
#include "src\Game.h"
#include "src\MapConstructor.h"
#include "src\ClassParser.h"
 int main()
{
    std::cout << "Do you Want to edit the Map?\n(y:n)\n";
    std::string value0;
    std::cin >> value0;
    if(value0[0] == 'y')
    {
        MapConstructor game;
        if(game.Construct(1024,1024,1,1))
            game.Start();
    }
    else
    {
        Game game;
        std::cout << "Do you want to see triggerboxes?\n(y:n)\n";
        std::string value;
        std::cin >> value;
        if(value[0] == 'y')
            game.isTriggersVisible = true;
        if(game.Construct(1024,1024,1,1))
            game.Start();
    }
}