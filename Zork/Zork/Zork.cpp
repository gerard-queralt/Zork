#include <iostream>
#include <string>
#include "Game/World.h"

using namespace std;

int main()
{
    World world;
    string args;
    
    while (true) {
        cout << "> ";
        getline(cin, args);
        world.Update();
    }

    return 0;
}
