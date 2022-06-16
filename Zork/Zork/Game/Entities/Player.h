#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include "Creature.h"

class Player : public Creature
{
	Player(const string& name, const string& description, Room* location);
	~Player();
};

#endif // _PLAYER_INCLUDE
