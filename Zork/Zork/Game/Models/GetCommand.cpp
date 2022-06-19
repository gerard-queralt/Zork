#include "GetCommand.h"
#include <iostream>

GetCommand::GetCommand(Item* i_target)
{
	m_target = i_target;
}

GetCommand::~GetCommand()
{
}

void GetCommand::Do(Player* i_player)
{
	i_player->Get(m_target);
}
