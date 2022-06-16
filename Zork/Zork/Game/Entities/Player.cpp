#include "Player.h"

Player::Player(const string& name, const string& description, Room* location = NULL) : Creature(name, description, location)
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
