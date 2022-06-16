#ifndef _WORLD_INCLUDE
#define _WORLD_INCLUDE

#include <vector>
#include "Entities/Entity.h"
#include "Entities/Player.h"
using namespace std;

class World
{
public:
	World();
	~World();
	void Update();
private:
	Player* player;
	vector<Entity*> entities;
};

#endif // _WORLD_INCLUDE
