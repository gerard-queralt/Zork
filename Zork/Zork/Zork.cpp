#include <iostream>
#include <string>
#include "Game/World.h"

using namespace std;

int main()
{
    World world;
    string args;
    
    while (world.Playing()) {
        cout << "> ";
        getline(cin, args);
        world.Update(args);
    }

    cout << "Press enter to exit the game." << endl;
    getchar();

    return 0;
}
