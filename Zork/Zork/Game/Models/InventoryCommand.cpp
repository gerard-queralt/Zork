#include "InventoryCommand.h"

InventoryCommand::InventoryCommand()
{
}

InventoryCommand::~InventoryCommand()
{
}

void InventoryCommand::Do(Player* i_player)
{
	i_player->Look();
}
