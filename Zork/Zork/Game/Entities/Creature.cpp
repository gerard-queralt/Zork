#include "Creature.h"

Creature::Creature(const string& i_name, const string& i_description, Room* i_location, int i_maxHP) : Entity(i_name, i_description)
{
	m_location = i_location;
	m_maxHP = i_maxHP;
	m_curHP = i_maxHP;
	m_combatTarget = NULL;
	m_weapon = NULL;
	m_dead = false;
	m_type = CREATURE;
}

Creature::~Creature()
{
}

void Creature::Update()
{
	if (!IsDead()) {
		Entity::Update();
		AttackTargetWithWeapon();
	}
}

void Creature::Enter(Room* i_room)
{
	m_location = i_room;
}

void Creature::Drop(Item* i_item)
{
	m_location->AddEntity(this->RemoveEntity(i_item));
}

void Creature::SetCombatTarget(Creature* i_combatTarget)
{
	m_combatTarget = i_combatTarget;
}

void Creature::SetWeapon(Item* i_weapon)
{
	m_weapon = i_weapon;
}

bool Creature::IsDead()
{
	return m_dead;
}

void Creature::AttackTargetWithWeapon()
{
	if (m_combatTarget != NULL && m_weapon != NULL && m_location->Contains(m_combatTarget)) {
		m_combatTarget->TakeDamage(m_weapon->GetDamage());
	}
}

void Creature::TakeDamage(int i_dmg)
{
	m_curHP -= i_dmg;
	if (m_curHP <= 0) {
		Die();
	}
}

void Creature::Die()
{
	m_dead = true;
	for (Entity* entity : m_contains) {
		if (entity->GetType() == ITEM) {
			Drop((Item*)entity);
		}
	}
}
