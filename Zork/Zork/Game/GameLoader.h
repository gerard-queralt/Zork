#ifndef _GAMELOADER_INCLUDE
#define _GAMELOADER_INCLUDE

#include <vector>
#include "Entities/Entity.h"
#include "Entities/Player.h"

class GameLoader
{
public:
	static std::vector<Entity*> LoadEntities(Player** player);
};

#endif // _GAMELOADER_INCLUDE
