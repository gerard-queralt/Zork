#include <iostream>
#include "Room.h"
#include "Exit.h"

Room::Room(const string& i_name, const string& i_description) : Entity(i_name, i_description)
{
	m_type = ROOM;
}

Room::~Room()
{
}

void Room::Look() const
{
	std::cout << m_name << endl;
	Entity::Look();
	for (Entity* entity : m_contains) {
		if (entity->GetType() != EXIT) {
			cout << "You see ";
		}
		entity->Look();
	}
}

bool Room::Contains(Entity* i_entity)
{
	if (Entity::Contains(i_entity)) {
		return true;
	}
	for (Entity* eInRoom : m_contains) {
		if (eInRoom->GetType() == ITEM && eInRoom->Contains(i_entity)) {
			return true;
		}
	}
	return false;
}

Entity* Room::RemoveEntity(Entity* i_entity)
{
	if (Entity::Contains(i_entity)) {
		return Entity::RemoveEntity(i_entity);
	}
	for (Entity* eInRoom : m_contains) {
		if (eInRoom->GetType() == ITEM) {
			Entity* eRemoved = eInRoom->RemoveEntity(i_entity);
			if (eRemoved != NULL) {
				return eRemoved;
			}
		}
	}
	return NULL;
}

Room* Room::AccessRoomInDirection(Direction i_direction, const list<Entity*>& i_playerInventory)
{
	for (Entity* entity : m_contains) {
		if (entity->GetType() == EXIT && ((Exit*)entity)->GetDirection() == i_direction) {
			bool unlocked = !((Exit*)entity)->IsLocked();
			bool unlockable = !unlocked && ((Exit*)entity)->Unlock(i_playerInventory);
			if (unlocked || unlockable) {
				return ((Exit*)entity)->GetRoomFrom(this);
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

