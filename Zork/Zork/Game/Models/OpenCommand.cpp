#include "OpenCommand.h"

OpenCommand::OpenCommand(Item* i_target)
{
	m_target = i_target;
}

OpenCommand::~OpenCommand()
{
}

void OpenCommand::Do(Player* i_player)
{
	i_player->Open(m_target);
}
