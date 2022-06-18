#include "GameLoader.h"
#include "EntityFinder.h"

GameLoader::LoadedResult GameLoader::LoadEntities()
{
    vector<Entity*> entities;

    vector<Item*> items = LoadItems();
    entities.insert(entities.end(), items.begin(), items.end());

    vector<Room*> rooms = LoadRooms(entities);
    entities.insert(entities.end(), rooms.begin(), rooms.end());

    vector<Exit*> exits = LoadExits(entities);
    entities.insert(entities.end(), exits.begin(), exits.end());

    Player* player = new Player("Hero", "That's you!");
    player->Enter(rooms[0]);

    entities.push_back(player);

    LoadedResult result;
    result.entities = entities;
    result.player = player;

    return result;
}

vector<Item*> GameLoader::LoadItems()
{
    vector<Item*> items;

    Item* houseKey = new Item("Key", "a small key.", true, false);
    Item* keyChest = new Item("Chest", "a small chest with its lid ajar.", false, true);
    keyChest->AddEntity(houseKey);
    keyChest->Close();
    Item* knife = new Item("Knife", "a kitchen knife", true, false);
    Item* rune = new Item("Stone", "an odd stone with weird markings", true, false);
    Item* sword = new Item("Sword", "a sword with Stones carved over it.", true, false);

    items.push_back(houseKey);
    items.push_back(keyChest);
    items.push_back(knife);
    items.push_back(rune);
    items.push_back(sword);

    return items;
}

vector<Room*> GameLoader::LoadRooms(const vector<Entity*>& existingEntities)
{
    vector<Room*> rooms;

    Room* westHouse = new Room("West of House", "This is an open field west of a white house.");

    Room* forest = new Room("Forest", "This is a forest, with trees in all directions around you.\nYou feel like you shouldn't go further.");
    Entity* keyChest = EntityFinder::FindEntityByName("Chest", existingEntities);
    forest->AddEntity(keyChest);

    Room* house = new Room("House", "You are in the living room of the house.");
    Entity* knife = EntityFinder::FindEntityByName("Knife", existingEntities);
    house->AddEntity(knife);

    Room* cellar = new Room("Cellar", "You are in a dark and damp cellar.");

    Room* ancientRoom = new Room("Weird room", "You are in a room noone has entered in years. The cobwebs covering the walls almost prevent you from seeing strange symbols and drawings on them.");
    Entity* sword = EntityFinder::FindEntityByName("Sword", existingEntities);
    ancientRoom->AddEntity(sword);

    Room* smallCave = new Room("Small cave", "You are in a narrow room barely lit by the light coming from the house above.");
    Entity* rune = EntityFinder::FindEntityByName("Stone", existingEntities);
    smallCave->AddEntity(rune); //will be held by mob in the future

    Room* trollRoom = new Room("The Troll room", "You are in a tall and spacious room. Some natural light filters from the ceiling avobe. Bloodstains and deep scratches mar the walls.");

    rooms.push_back(westHouse);
    rooms.push_back(forest);
    rooms.push_back(house);
    rooms.push_back(cellar);
    rooms.push_back(ancientRoom);
    rooms.push_back(smallCave);
    rooms.push_back(trollRoom);

    return rooms;
}

vector<Exit*> GameLoader::LoadExits(const vector<Entity*>& existingEntities)
{
    vector<Exit*> exits;

    Entity* westHouse = EntityFinder::FindEntityByName("West of House", existingEntities);
    Entity* forest = EntityFinder::FindEntityByName("Forest", existingEntities);
    Entity* house = EntityFinder::FindEntityByName("House", existingEntities);
    Entity* cellar = EntityFinder::FindEntityByName("Cellar", existingEntities);
    Entity* ancientRoom = EntityFinder::FindEntityByName("Weird room", existingEntities);
    Entity* smallCave = EntityFinder::FindEntityByName("Small cave", existingEntities);
    Entity* trollRoom = EntityFinder::FindEntityByName("The Troll room", existingEntities);
    
    if (westHouse->getType() == ROOM && forest->getType() == ROOM) {
        Exit* westToForest = new Exit("Entrance Forest", "There is a faded path between two trees.", WEST, (Room*)westHouse, (Room*)forest);
        westHouse->AddEntity(westToForest);
        forest->AddEntity(westToForest->Reverse());
        exits.push_back(westToForest);
    }
    
    if (westHouse->getType() == ROOM && house->getType() == ROOM) {
        Exit* westToHouse = new Exit("House door", "There is a door with an ornate keyhole.", EAST, (Room*)westHouse, (Room*)house);
        westToHouse->LockWith("Key");
        westHouse->AddEntity(westToHouse);
        house->AddEntity(westToHouse->Reverse());
        exits.push_back(westToHouse);
    }

    if (house->getType() == ROOM && ancientRoom->getType() == ROOM) {
        Exit* ancientDoor = new Exit("Ancient door", "The door is made of oak and has hollow shape where the lock should be.", SOUTH, (Room*)house, (Room*)ancientRoom);
        ancientDoor->LockWith("Stone");
        house->AddEntity(ancientDoor);
        ancientRoom->AddEntity(ancientDoor->Reverse());
        exits.push_back(ancientDoor);
    }

    if (house->getType() == ROOM && cellar->getType() == ROOM) {
        Exit* trapdoor = new Exit("Trap-door", "There is a trap-door on the floor.", DOWN, (Room*)house, (Room*)cellar);
        house->AddEntity(trapdoor);
        cellar->AddEntity(trapdoor->Reverse());
        exits.push_back(trapdoor);
    }

    if (cellar->getType() == ROOM && smallCave->getType() == ROOM) {
        Exit* caveEntrance = new Exit("Cave entrance", "There is a hole in the wall, big enough for you to fit through.", WEST, (Room*)cellar, (Room*)smallCave);
        cellar->AddEntity(caveEntrance);
        smallCave->AddEntity(caveEntrance->Reverse());
        exits.push_back(caveEntrance);
    }

    if (cellar->getType() == ROOM && trollRoom->getType() == ROOM) {
        Exit* trollEntrance = new Exit("Troll Room entrance", "There is an ominous arch carved in the wall.", NORTH, (Room*)cellar, (Room*)trollRoom);
        cellar->AddEntity(trollEntrance);
        trollRoom->AddEntity(trollEntrance->Reverse());
        exits.push_back(trollEntrance);
    }

    return exits;
}
