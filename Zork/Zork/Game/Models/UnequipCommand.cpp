#include "UnequipCommand.h"

UnequipCommand::UnequipCommand()
{
}

UnequipCommand::~UnequipCommand()
{
}

void UnequipCommand::Do(Player* i_player)
{
	i_player->Unequip();
}
