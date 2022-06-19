#include "EntityFinder.h"

Entity* EntityFinder::FindEntityByName(const string& i_name, const vector<Entity*>& i_entities)
{
    for (Entity* entity : i_entities) {
        if (entity->GetName() == i_name)
            return entity;
    }

    return NULL;
}

vector<Entity*> EntityFinder::FindEntitiesByType(EntityType i_type, const vector<Entity*>& i_entities)
{
    vector<Entity*> entitiesOfType;

    for (Entity* entity : i_entities) {
        if (entity->GetType() == i_type)
            entitiesOfType.push_back(entity);
    }

    return entitiesOfType;
}
