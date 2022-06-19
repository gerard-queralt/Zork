#include "Exit.h"

#include <iostream>
#include <vector>
#include "../EntityFinder.h"

map<Direction, string> Exit::s_directionName = {
	{NORTH, "to the north"},
	{SOUTH, "to the south"},
	{EAST, "to the east"},
	{WEST, "to the west"},
	{UP, "up from here"},
	{DOWN, "down from here"},
};

Exit::Exit(const string& i_name, const string& i_description, Direction i_direction, Room* i_from, Room* i_to) : Entity(i_name, i_description)
{
	m_direction = i_direction;
	m_from = i_from;
	m_to = i_to;
	m_locked = false;
	m_type = EXIT;
}

Exit::~Exit()
{
}

void Exit::Look() const
{
	cout << "You see the " << m_to->GetName() << " " << s_directionName[m_direction] << ". ";
	Entity::Look();
}

Direction Exit::GetDirection()
{
	return m_direction;
}

Room* Exit::GetRoomFrom(Room* i_from)
{
	if (i_from->GetName() == m_from->GetName()) {
		return m_to;
	}
	if (i_from->GetName() == m_to->GetName()) {
		return m_from;
	}
	return NULL;
}

void Exit::AddSelfToRooms()
{
	m_from->AddEntity(this);
	m_to->AddEntity(this->Reverse());
}

Exit* Exit::Reverse()
{
	//If direction is even, add 1 to get reverse. If it's odd, substract 1
	Direction reverseDirection = static_cast<Direction>(m_direction + 1 * pow(-1, m_direction % 2));
	Exit* reverse = new Exit(m_name, m_description, reverseDirection, m_to, m_from);
	if (m_locked) {
		reverse->LockWith(m_keyName);
	}
	return reverse;
}

void Exit::LockWith(const string& i_keyName)
{
	m_locked = true;
	m_keyName = i_keyName;
}

bool Exit::Unlock(const list<Entity*>& i_inventory)
{
	vector<Entity*> invVector(i_inventory.begin(), i_inventory.end());
	if (EntityFinder::FindEntityByName(m_keyName, invVector) != NULL) {
		cout << "You unlock the way with the " << m_keyName << "." << endl;
		m_locked = false;
	}
	return !m_locked;
}

bool Exit::IsLocked()
{
	return m_locked;
}
