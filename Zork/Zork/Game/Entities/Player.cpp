#include "Player.h"

#include <iostream>

Player::Player(const string& i_name, const string& i_description) : Creature(i_name, i_description, NULL, 25) //no need to set maxHP externally
{
	m_type = PLAYER;
}

Player::~Player()
{
}

void Player::Look() const
{
	if (m_contains.empty()) {
		cout << "You have nothing on you." << endl;
	}
	else {
		cout << "You have:" << endl;
		for (Entity* entity : m_contains) {
			cout << "  ";
			entity->Look();
		}
	}
}

void Player::Enter(Room* i_room)
{
	Creature::Enter(i_room);
	m_location->Look();
}

void Player::Move(Direction i_direction)
{
	Room* nextRoom = m_location->AccessRoomInDirection(i_direction, m_contains);
	if (nextRoom != NULL) {
		Enter(nextRoom);
	}
}

void Player::Get(Item* i_item)
{
	if (m_location->Contains(i_item)) {
		if (i_item->CanBePicked()) {
			this->AddEntity(m_location->RemoveEntity(i_item));
			cout << "Taken." << endl;
		}
		else {
			cout << "That can't be picked up." << endl;
		}
	}
	else {
		cout << "That's not an item in this room." << endl;
	}
}

void Player::Drop(Item* i_item)
{
	if (this->Contains(i_item)) {
		m_location->AddEntity(this->RemoveEntity(i_item));
		cout << "Dropped." << endl;
	}
	else {
		cout << "You don't have that." << endl;
	}
}

void Player::Open(Item* i_item)
{
	if (m_location->Contains(i_item)) {
		i_item->Open();
	}
	else {
		cout << "That's not an item in this room." << endl;
	}
}

void Player::LookAround()
{
	m_location->Look();
}

void Player::Put(Item* i_item, Item* i_container)
{
	if (this->Contains(i_item) && m_location->Contains(i_container)) {
		i_container->AddEntity(this->RemoveEntity(i_item));
		if (i_container->Contains(i_item)) { //added successfully
			cout << "Item put." << endl;
		}
	}
	else {
		cout << "You don't have that." << endl;
	}
}
