#include "PutCommand.h"

PutCommand::PutCommand(Item* i_target, Item* i_container)
{
	m_target = i_target;
	m_container = i_container;
}

PutCommand::~PutCommand()
{
}

void PutCommand::Do(Player* i_player)
{
	i_player->Put(m_target, m_container);
}
