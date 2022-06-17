#ifndef _GAMELOADER_INCLUDE
#define _GAMELOADER_INCLUDE

#include <vector>
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Item.h"
#include "Entities/Room.h"
#include "Entities/Exit.h"

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
	static vector<Item*> LoadItems();
	static vector<Room*> LoadRooms(const vector<Entity*>& existingEntities);
	static vector<Exit*> LoadExits(const vector<Entity*>& existingEntities);
};

#endif // _GAMELOADER_INCLUDE
