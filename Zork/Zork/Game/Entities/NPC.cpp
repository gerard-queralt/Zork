#include "NPC.h"

NPC::NPC(const string& i_name, const string& i_description, Room* i_location, int i_maxHP) : Creature(i_name, i_description, i_location, i_maxHP)
{
	m_type = EntityType::NPC;
}

NPC::~NPC()
{
}
