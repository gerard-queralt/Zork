#include "Npc.h"

Npc::Npc(const string& i_name, const string& i_description, Room* i_location, int i_maxHP) : Creature(i_name, i_description, i_location, i_maxHP)
{
	m_type = NPC;
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
