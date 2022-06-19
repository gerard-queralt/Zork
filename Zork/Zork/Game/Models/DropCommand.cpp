#include "DropCommand.h"

DropCommand::DropCommand(Item* i_target)
{
	m_target = i_target;
}

DropCommand::~DropCommand()
{
}

void DropCommand::Do(Player* i_player)
{
	i_player->Drop(m_target);
}
