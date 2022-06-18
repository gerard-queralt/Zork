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
		if (entity->getType() != EXIT) {
			cout << "You see ";
		}
		entity->Look();
	}
}

bool Room::Contains(Entity* entity)
{
	if (Entity::Contains(entity)) {
		return true;
	}
	for (Entity* eInRoom : contains) {
		if (eInRoom->getType() == ITEM && eInRoom->Contains(entity)) {
			return true;
		}
	}
	return false;
}

Entity* Room::RemoveEntity(Entity* entity)
{
	if (Entity::Contains(entity)) {
		return Entity::RemoveEntity(entity);
	}
	for (Entity* eInRoom : contains) {
		if (eInRoom->getType() == ITEM) {
			Entity* eRemoved = eInRoom->RemoveEntity(entity);
			if (eRemoved != NULL) {
				return eRemoved;
			}
		}
	}
	return NULL;
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

