#include "AttackCommand.h"

AttackCommand::AttackCommand(Creature* i_target)
{
	m_target = i_target;
	m_weapon = NULL;
}

AttackCommand::AttackCommand(Creature* i_target, Item* i_weapon) : AttackCommand(i_target)
{
	m_weapon = i_weapon;
}

AttackCommand::~AttackCommand()
{
}

void AttackCommand::Do(Player* i_player)
{
}
