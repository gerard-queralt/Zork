#include "MoveCommand.h"

MoveCommand::MoveCommand(Direction i_direction)
{
	m_direction = i_direction;
}

MoveCommand::~MoveCommand()
{
}

void MoveCommand::Do(Player* i_player)
{
	i_player->Move(m_direction);
}
