#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include "Creature.h"
#include "Item.h"

class Player : public Creature
{
public:
	Player(const string& name, const string& description);
	~Player();

	void Enter(Room* room);

	void Move(Direction direction);
	void Get(Item* item);
};

#endif // _PLAYER_INCLUDE
