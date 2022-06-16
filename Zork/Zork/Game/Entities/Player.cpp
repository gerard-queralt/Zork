#include "Player.h"

Player::Player(const string& name, const string& description, Room* location) : Creature(name, description, location)
{
	type = PLAYER;
}

Player::~Player()
{
}
