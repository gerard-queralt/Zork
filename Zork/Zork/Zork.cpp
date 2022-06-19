#include <iostream>
#include <string>
#include "Game/World.h"

using namespace std;

int main()
{
    cout << "Welcome to my small tribute of the game Zork. I hope you'll enjoy it!" << endl;
    cout << "Your objective is to slay a monster lurking beneath a house in the middle of the woods." << endl;
    cout << "But be careful! Even if it's slow, it's very tough. You will most likely need a special weapon to defeat it." << endl;
    cout << "For more information about the game or the commands you can input, please visit https://github.com/gerard-queralt/Zork." << endl;
    cout << endl << endl;

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
