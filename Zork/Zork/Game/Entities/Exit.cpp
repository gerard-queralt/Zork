#include "Exit.h"

#include <iostream>
#include <vector>
#include "../EntityFinder.h"

map<Direction, string> Exit::directionName = {
	{NORTH, "north"},
	{SOUTH, "south"},
	{EAST, "east"},
	{WEST, "west"}
};

Exit::Exit(const string& name, const string& description, Direction direction, Room* from, Room* to) : Entity(name, description)
{
	this->direction = direction;
	this->from = from;
	this->to = to;
	this->locked = false;
	this->type = EXIT;
}

Exit::~Exit()
{
}

void Exit::Look() const
{
	cout << "You see the " << to->getName() << " to the " << directionName[direction] << ". ";
	Entity::Look();
}

Direction Exit::getDirection()
{
	return direction;
}

Room* Exit::getRoomFrom(Room* from)
{
	if (from->getName() == this->from->getName()) {
		return this->to;
	}
	if (from->getName() == this->to->getName()) {
		return this->from;
	}
	return NULL;
}

Exit* Exit::Reverse()
{
	//If direction is even, add 1 to get reverse. If it's odd, substract 1
	Direction reverseDirection = static_cast<Direction>(direction + 1 * pow(-1, direction % 2));
	Exit* reverse = new Exit(name, description, reverseDirection, to, from);
	if (locked) {
		reverse->LockWith(keyName);
	}
	return reverse;
}

void Exit::LockWith(const string& keyName)
{
	locked = true;
	this->keyName = keyName;
}

bool Exit::Unlock(const list<Entity*>& inventory)
{
	vector<Entity*> invVector(inventory.begin(), inventory.end());
	if (EntityFinder::FindEntityByName(keyName, invVector) != NULL) {
		cout << "You unlock the way with a " << keyName << "." << endl;
		locked = false;
	}
	return !locked;
}

bool Exit::isLocked()
{
	return locked;
}
