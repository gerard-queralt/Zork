#include <iostream>
#include "Room.h"

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
