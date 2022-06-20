#ifndef _ENTITYFINDER_INCLUDE
#define _ENTITYFINDER_INCLUDE

#include <string>
#include <vector>
#include "Entities/Entity.h"

using namespace std;

class EntityFinder
{
public:
	static Entity* FindEntityByName(const string& i_name, const vector<Entity*>& i_entities);
};

#endif // _ENTITYFINDER_INCLUDE
