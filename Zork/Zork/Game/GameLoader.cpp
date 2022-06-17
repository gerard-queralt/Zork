#include "GameLoader.h"
#include "Entities/Room.h"

GameLoader::LoadedResult GameLoader::LoadEntities()
{
    vector<Entity*> entities;

    vector<Room*> rooms = LoadRooms();

    Player* player = new Player("Hero", "That's you!");
    player->Enter(rooms[0]);

    entities.insert(entities.end(), rooms.begin(), rooms.end());
    entities.push_back(player);

    LoadedResult result;
    result.entities = entities;
    result.player = player;

    return result;
}

vector<Room*> GameLoader::LoadRooms()
{
    vector<Room*> rooms;

    Room* start = new Room("West of House", "This is an open field west of a white house, with a boarded front door.");

    rooms.push_back(start);

    return rooms;
}
