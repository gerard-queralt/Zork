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
