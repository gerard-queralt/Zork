#include "EntityFinder.h"

Entity* EntityFinder::FindEntityByName(const string& i_name, const vector<Entity*>& i_entities)
{
    for (Entity* entity : i_entities) {
        if (entity->GetName() == i_name)
            return entity;
    }

    return NULL;
}
