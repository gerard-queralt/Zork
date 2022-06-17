#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include "Creature.h"

class Player : public Creature
{
public:
	Player(const string& name, const string& description);
	~Player();

	void Enter(Room* room);

	void Move(Direction direction);
};

#endif // _PLAYER_INCLUDE
