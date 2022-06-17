#include <iostream>
#include "Room.h"
#include "Exit.h"

Room::Room(const string& name, const string& description) : Entity(name, description)
{
	type = ROOM;
}

Room::~Room()
{
}

void Room::Look() const
{
	std::cout << name << endl;
	Entity::Look();
	for (Entity* entity : contains) {
		entity->Look();
	}
}

Room* Room::getRoomInDirection(Direction direction)
{
	for (Entity* entity : contains) {
		if (entity->getType() == EXIT && ((Exit*)entity)->getDirection() == direction) {
			return ((Exit*)entity)->getRoomFrom(this);
		}
	}
	return NULL;
}
