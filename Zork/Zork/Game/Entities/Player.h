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
	void Drop(Item* i_item);
	void SetWeapon(Item* i_weapon);

	void Move(Direction i_direction);
	void Get(Item* i_item);
	void Open(Item* i_item);
	void LookAround();
	void Put(Item* i_item, Item* i_container);
	void Attack(Creature* i_target, Item* i_weapon);
};

#endif // _PLAYER_INCLUDE
