#include "GameLoader.h"
#include "EntityFinder.h"
#include "Entities/Room.h"

GameLoader::LoadedResult GameLoader::LoadEntities()
{
    vector<Entity*> entities;

    vector<Item*> items = LoadItems();
    entities.insert(entities.end(), items.begin(), items.end());

    vector<Room*> rooms = LoadRooms(entities);
    entities.insert(entities.end(), rooms.begin(), rooms.end());

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

    Item* mailbox = new Item("Mailbox", "a small mailbox");

    items.push_back(mailbox);

    return items;
}

vector<Room*> GameLoader::LoadRooms(const vector<Entity*>& existingEntities)
{
    vector<Room*> rooms;

    Room* start = new Room("West of House", "This is an open field west of a white house, with a boarded front door.");
    Entity* mailbox = EntityFinder::FindEntityByName("Mailbox", existingEntities);
    start->AddEntity(mailbox);

    rooms.push_back(start);

    return rooms;
}
