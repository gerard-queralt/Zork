#include "DropCommand.h"

DropCommand::DropCommand(Item* target)
{
	this->target = target;
}

DropCommand::~DropCommand()
{
}

void DropCommand::Do(Player* player)
{
}
