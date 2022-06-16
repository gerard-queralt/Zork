#include "Player.h"

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
