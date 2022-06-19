#include "Npc.h"
#include <iostream>

Npc::Npc(const string& i_name, const string& i_description, Room* i_location, int i_maxHP) : Creature(i_name, i_description, i_location, i_maxHP)
{
	m_type = NPC;
	i_location->AddEntity(this);
}

Npc::~Npc()
{
}

void Npc::Update()
{
	if (!IsDead()) {
		Creature::Update();
		AttackTargetWithWeapon();
	}
}

void Npc::Drop(Item* i_item)
{
	cout << "They drop ";
	i_item->Look();
	Creature::Drop(i_item);
}

void Npc::AttackTargetWithWeapon()
{
	if (CanAttackTarget()) {
		cout << "The " << m_name << " attacks ";
		if (m_combatTarget->GetName() == "Hero") {
			cout << "you";
		}
		else {
			cout << m_combatTarget->GetName();
		}
		cout << "." << endl;
		Creature::AttackTargetWithWeapon();
	}
}

void Npc::TakeDamage(int i_dmg)
{
	cout << "The " << m_name << " takes " << i_dmg << " damage." << endl;
	Creature::TakeDamage(i_dmg);
}

void Npc::Die()
{
	cout << "The " << m_name << " dies." << endl;
	Creature::Die();
}
