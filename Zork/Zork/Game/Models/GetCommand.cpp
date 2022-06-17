#include "GetCommand.h"
#include <iostream>

GetCommand::GetCommand(Item* target)
{
	this->target = target;
}

GetCommand::~GetCommand()
{
}

void GetCommand::Do(Player* player)
{
	player->Get(target);
}
