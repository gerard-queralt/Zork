#include "Creature.h"

Creature::Creature(const string& name, const string& description, Room* location) : Entity(name, description)
{
	this->location = location;
	type = CREATURE;
}

Creature::~Creature()
{
}
