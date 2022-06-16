#include "Creature.h"

Creature::Creature(const string& name, const string& description) : Entity(name, description)
{
	type = CREATURE;
}

Creature::~Creature()
{
}
