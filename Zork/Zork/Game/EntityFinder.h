#ifndef _ENTITYFINDER_INCLUDE
#define _ENTITYFINDER_INCLUDE

#include <string>
#include <vector>
#include "Entities/Entity.h"

using namespace std;

class EntityFinder
{
public:
	static Entity* FindEntityByName(const string& name, const vector<Entity*>& entities);
	static vector<Entity*> FindEntitiesByType(EntityType type, const vector<Entity*>& entities);
};

#endif // _ENTITYFINDER_INCLUDE
