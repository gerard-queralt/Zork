#include "Room.h"

Room::Room()
{
}

Room::~Room()
{
}

void Room::Look() const
{
	Entity::Look();
	for (Entity* entity : contains) {
		entity->Look();
	}
}
