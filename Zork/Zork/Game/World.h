#ifndef _WORLD_INCLUDE
#define _WORLD_INCLUDE

#include <vector>
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "CommandParser.h"
using namespace std;

class World
{
public:
	World();
	~World();
	void Update(const string& i_args);

	bool Playing();

private:
	Player* m_player;
	vector<Entity*> m_entities;

	CommandParser* m_parser;
};

#endif // _WORLD_INCLUDE
