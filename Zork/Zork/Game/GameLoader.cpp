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

    items.push_back(houseKey);
    items.push_back(keyChest);

    return items;
}

vector<Room*> GameLoader::LoadRooms(const vector<Entity*>& existingEntities)
{
    vector<Room*> rooms;

    Room* westHouse = new Room("West of House", "This is an open field west of a white house, with a boarded front door.");

    Room* house = new Room("House", "You are in the living room of the house.");

    Room* forest = new Room("Forest", "This is a forest, with trees in all directions around you.\nYou feel like you shouldn't go further.");
    Entity* keyChest = EntityFinder::FindEntityByName("Chest", existingEntities);
    forest->AddEntity(keyChest);

    rooms.push_back(westHouse);
    rooms.push_back(house);
    rooms.push_back(forest);

    return rooms;
}

vector<Exit*> GameLoader::LoadExits(const vector<Entity*>& existingEntities)
{
    vector<Exit*> exits;

    Entity* westHouse = EntityFinder::FindEntityByName("West of House", existingEntities);
    Entity* house = EntityFinder::FindEntityByName("House", existingEntities);
    Entity* forest = EntityFinder::FindEntityByName("Forest", existingEntities);
    if (westHouse->getType() == ROOM && house->getType() == ROOM) {
        Exit* westToHouse = new Exit("House door", "There is a door with an ornate keyhole.", EAST, (Room*)westHouse, (Room*)house);
        westToHouse->LockWith("Key");
        westHouse->AddEntity(westToHouse);
        house->AddEntity(westToHouse->Reverse());
        exits.push_back(westToHouse);
    }
    if (westHouse->getType() == ROOM && forest->getType() == ROOM) {
        Exit* westToForest = new Exit("Entrance Forest", "There is a faded path between two trees.", WEST, (Room*)westHouse, (Room*)forest);
        westHouse->AddEntity(westToForest);
        forest->AddEntity(westToForest->Reverse());
        exits.push_back(westToForest);
    }

    return exits;
}
