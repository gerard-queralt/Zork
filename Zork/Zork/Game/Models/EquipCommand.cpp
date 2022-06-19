#include "EquipCommand.h"

EquipCommand::EquipCommand(Item* i_target)
{
	m_target = i_target;
}

EquipCommand::~EquipCommand()
{
}

void EquipCommand::Do(Player* i_player)
{
	i_player->SetWeapon(m_target);
}
