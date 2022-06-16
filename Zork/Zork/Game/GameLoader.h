#ifndef _GAMELOADER_INCLUDE
#define _GAMELOADER_INCLUDE

#include <vector>
#include "Game/Entities/Entity.h"

class GameLoader
{
public:
	static std::vector<Entity*> LoadEntities();
};

#endif // _GAMELOADER_INCLUDE
