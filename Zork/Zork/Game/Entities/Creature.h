#ifndef _CREATURE_INCLUDE
#define _CREATURE_INCLUDE

#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Creature : public Entity
{
public:
	Creature(const string& i_name, const string& i_description, Room* i_location, int i_maxHP);
	~Creature();
	virtual void Update();

	virtual void Enter(Room* i_room);
	virtual void Drop(Item* i_item);
	void SetCombatTarget(Creature* i_combatTarget);
	virtual void SetWeapon(Item* i_weapon);
	bool IsDead();

protected:
	bool CanAttackTarget();
	virtual void AttackTargetWithWeapon();
	virtual void TakeDamage(int i_dmg);
	virtual void Die();

	int m_maxHP;
	int m_curHP;
	bool m_dead;
	Room* m_location;
	Creature* m_combatTarget;
	Item* m_weapon;
};

#endif // _CREATURE_INCLUDE
