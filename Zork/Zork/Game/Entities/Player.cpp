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
	Room* nextRoom = location->getRoomInDirection(direction);
	if (nextRoom != NULL) {
		Enter(nextRoom);
	}
	else {
		cout << "You can't go in that direction." << endl;
	}
}
