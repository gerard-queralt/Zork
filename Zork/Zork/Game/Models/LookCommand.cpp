#include "LookCommand.h"

LookCommand::LookCommand()
{
}

LookCommand::~LookCommand()
{
}

void LookCommand::Do(Player* player)
{
	player->LookAround();
}
