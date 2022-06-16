#include "GameLoader.h"
#include "Entities/Room.h"
#include "Entities/Player.h"

std::vector<Entity*> GameLoader::LoadEntities()
{
    std::vector<Entity*> entities;

    Room* start = new Room("West of House", "This is an open field west of a white house, with a boarded front door.");

    entities.push_back(start);

    return entities;
}
