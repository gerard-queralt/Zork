#include "GameLoader.h"
#include "Entities/Room.h"

std::vector<Entity*> GameLoader::LoadEntities(Player** player)
{
    std::vector<Entity*> entities;

    Room* start = new Room("West of House", "This is an open field west of a white house, with a boarded front door.");

    *player = new Player("Hero", "That's you!", NULL);
    (*player)->Enter(start);

    entities.push_back(start);
    entities.push_back(*player);

    return entities;
}
