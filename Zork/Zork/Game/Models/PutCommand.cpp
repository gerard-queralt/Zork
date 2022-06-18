#include "PutCommand.h"

PutCommand::PutCommand(Item* target, Item* container)
{
	this->target = target;
	this->container = container;
}

PutCommand::~PutCommand()
{
}

void PutCommand::Do(Player* player)
{
	player->Put(target, container);
}
