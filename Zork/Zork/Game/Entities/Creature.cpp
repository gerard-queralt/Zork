#include "Creature.h"

Creature::Creature(const string& name, const string& description, Room* location, int maxHP) : Entity(name, description)
{
	this->location = location;
	this->maxHP = maxHP;
	this->curHP = maxHP;
	this->combatTarget = NULL;
	this->weapon = NULL;
	type = CREATURE;
}

Creature::~Creature()
{
}

void Creature::Enter(Room* room)
{
	location = room;
}

void Creature::SetCombatTarget(Creature* combatTarget)
{
	this->combatTarget = combatTarget;
}

void Creature::SetWeapon(Item* weapon)
{
	this->weapon = weapon;
}

void Creature::AttackTargetWithWeapon()
{
	if (combatTarget != NULL && weapon != NULL) {
		combatTarget->TakeDamage(weapon->GetDamage());
	}
}

void Creature::TakeDamage(int dmg)
{
	curHP -= dmg;
	if (curHP <= 0) {
		Die();
	}
}

void Creature::Die()
{
}
