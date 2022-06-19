#include "NPC.h"

NPC::NPC(const string& name, const string& description, Room* location) : Creature(name, description, location)
{
	type = EntityType::NPC;
}

NPC::~NPC()
{
}
