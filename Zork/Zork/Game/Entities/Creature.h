#ifndef _CREATURE_INCLUDE
#define _CREATURE_INCLUDE

#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Creature : public Entity
{
public:
	Creature(const string& name, const string& description, Room* location, int maxHP);
	~Creature();

	virtual void Enter(Room* room);
	void SetCombatTarget(Creature* combatTarget);
	void SetWeapon(Item* weapon);

protected:
	virtual void AttackTargetWithWeapon();
	virtual void TakeDamage(int dmg);
	virtual void Die();

	int maxHP;
	int curHP;
	Room* location;
	Creature* combatTarget;
	Item* weapon;
};

#endif // _CREATURE_INCLUDE
