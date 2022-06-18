#include "OpenCommand.h"

OpenCommand::OpenCommand(Item* target)
{
	this->target = target;
}

OpenCommand::~OpenCommand()
{
}

void OpenCommand::Do(Player* player)
{
	player->Open(target);
}
