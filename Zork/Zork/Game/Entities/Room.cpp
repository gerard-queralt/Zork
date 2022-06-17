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

Room* Room::AccessRoomInDirection(Direction direction, const list<Entity*>& playerInventory)
{
	for (Entity* entity : contains) {
		if (entity->getType() == EXIT && ((Exit*)entity)->getDirection() == direction) {
			bool unlocked = !((Exit*)entity)->isLocked();
			bool unlockable = !unlocked && ((Exit*)entity)->Unlock(playerInventory);
			if (unlocked || unlockable) {
				return ((Exit*)entity)->getRoomFrom(this);
			}
			else {
				cout << "It's locked." << endl;
				return NULL;
			}
		}
	}

	cout << "You can't go in that direction." << endl;
	return NULL;
}

