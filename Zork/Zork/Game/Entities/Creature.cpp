#include "Creature.h"

Creature::Creature(const string& name, const string& description, Room* location) : Entity(name, description)
{
	this->location = location;
	type = CREATURE;
}

Creature::~Creature()
{
}

void Creature::Enter(Room* room)
{
	location = room;
}

Room* Creature::getLocation()
{
	return location;
}
