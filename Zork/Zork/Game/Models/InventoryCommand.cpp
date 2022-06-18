#include "InventoryCommand.h"

InventoryCommand::InventoryCommand()
{
}

InventoryCommand::~InventoryCommand()
{
}

void InventoryCommand::Do(Player* player)
{
	player->Look();
}
