#include <iostream>
#include "src\Game.h"
#include "string"
 int main()
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