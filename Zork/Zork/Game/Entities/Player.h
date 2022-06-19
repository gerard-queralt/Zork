#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include "Creature.h"
#include "Item.h"

class Player : public Creature
{
public:
	Player();
	~Player();

	void Look() const;

	void Enter(Room* i_room);

	void Move(Direction i_direction);
	void Get(Item* i_item);
	void Drop(Item* i_item);
	void Open(Item* i_item);
	void LookAround();
	void Put(Item* i_item, Item* i_container);
};

#endif // _PLAYER_INCLUDE
