#include "MoveCommand.h"

MoveCommand::MoveCommand(Direction direction)
{
	this->direction = direction;
}

MoveCommand::~MoveCommand()
{
}

void MoveCommand::Do(Player* player)
{
	player->Move(direction);
}
