#include "EntityFinder.h"

Entity* EntityFinder::FindEntityByName(const string& name, const vector<Entity*>& entities)
{
    for (Entity* entity : entities) {
        if (entity->getName() == name)
            return entity;
    }

    return NULL;
}

vector<Entity*> EntityFinder::FindEntitiesByType(Entity::EntityType type, const vector<Entity*>& entities)
{
    vector<Entity*> entitiesOfType;

    for (Entity* entity : entities) {
        if (entity->getType() == type)
            entitiesOfType.push_back(entity);
    }

    return entitiesOfType;
}
