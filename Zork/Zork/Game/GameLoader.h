#ifndef _GAMELOADER_INCLUDE
#define _GAMELOADER_INCLUDE

#include <vector>
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Item.h"

using namespace std;

class GameLoader
{
public:
	struct LoadedResult {
		Player* player;
		vector<Entity*> entities;
	};

	static LoadedResult LoadEntities();

private:
	static vector<Room*> LoadRooms(const vector<Item*>& items);
	static vector<Item*> LoadItems();
};

#endif // _GAMELOADER_INCLUDE
