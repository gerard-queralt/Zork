#include "Player.h"

#include <iostream>

Player::Player(const string& name, const string& description) : Creature(name, description, NULL)
{
	type = PLAYER;
}

Player::~Player()
{
}

void Player::Look() const
{
	if (contains.empty()) {
		cout << "You have nothing on you." << endl;
	}
	else {
		cout << "You have:" << endl;
		for (Entity* entity : contains) {
			cout << "  ";
			entity->Look();
		}
	}
}

void Player::Enter(Room* room)
{
	Creature::Enter(room);
	location->Look();
}

void Player::Move(Direction direction)
{
	Room* nextRoom = location->AccessRoomInDirection(direction, contains);
	if (nextRoom != NULL) {
		Enter(nextRoom);
	}
}

void Player::Get(Item* item)
{
	if (location->Contains(item)) {
		if (item->CanBePicked()) {
			this->AddEntity(location->RemoveEntity(item));
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

void Player::Drop(Item* item)
{
	if (this->Contains(item)) {
		location->AddEntity(this->RemoveEntity(item));
	}
	else {
		cout << "You don't have that." << endl;
	}
}

void Player::Open(Item* item)
{
	if (location->Contains(item)) {
		item->Open();
	}
	else {
		cout << "That's not an item in this room." << endl;
	}
}

void Player::LookAround()
{
	location->Look();
}

void Player::Put(Item* item, Item* container)
{
	if (this->Contains(item) && location->Contains(container)) {
		container->AddEntity(this->RemoveEntity(item));
	}
	else {
		cout << "You don't have that." << endl;
	}
}
