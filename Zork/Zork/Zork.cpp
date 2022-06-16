#include <iostream>
#include "Game/World.h"

int main()
{
    World world;
    world.Init();
    
    while (true) {
        world.Update();
    }

    return 0;
}
