#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include "Creature.h"

class Player : public Creature
{
public:
	Player(const string& name, const string& description, Room* location);
	~Player();

	void Enter(Room* room);
};

#endif // _PLAYER_INCLUDE
