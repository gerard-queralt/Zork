#ifndef _EQUIPCOMMAND_INCLUDE
#define _EQUIPCOMMAND_INCLUDE

#include "Command.h"
#include "..\Entities\Item.h"

class EquipCommand : public Command
{
public:
	EquipCommand(Item* i_target);
	~EquipCommand();
	void Do(Player* i_player);

private:
	Item* m_target;
};

#endif // _EQUIPCOMMAND_INCLUDE
