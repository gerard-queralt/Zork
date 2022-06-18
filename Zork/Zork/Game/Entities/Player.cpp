#include "Player.h"

#include <iostream>

Player::Player(const string& name, const string& description) : Creature(name, description, NULL)
{
	type = PLAYER;
}

Player::~Player()
{
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
			this->AddEntity(item);
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
}
