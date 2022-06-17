#include <iostream>
#include "Exit.h"

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
	this->type = EXIT;

	AddSelfToRooms();
}

Exit::~Exit()
{
}

void Exit::Look() const
{
	cout << "You see the " << to->getName() << " to the " << directionName[direction] << ". ";
	Entity::Look();
}

Exit* Exit::Reverse()
{
	//If direction is even, add 1 to get reverse. If it's odd, substract 1
	Direction reverseDirection = static_cast<Direction>(direction + 1 * pow(-1, direction % 2));
	return new Exit(name, description, reverseDirection, to, from);
}

void Exit::AddSelfToRooms()
{
	from->AddEntity(this);
	to->AddEntity(this->Reverse());
}
