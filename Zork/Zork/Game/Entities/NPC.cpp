#include "NPC.h"

NPC::NPC(const string& name, const string& description, Room* location, int maxHP) : Creature(name, description, location, maxHP)
{
	type = EntityType::NPC;
}

NPC::~NPC()
{
}
