#include "LookCommand.h"

LookCommand::LookCommand()
{
}

LookCommand::~LookCommand()
{
}

void LookCommand::Do(Player* i_player)
{
	i_player->LookAround();
}
