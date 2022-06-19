#ifndef _UNEQUIPCOMMAND_INCLUDE
#define _UNEQUIPCOMMAND_INCLUDE

#include "Command.h"
#include "..\Entities\Item.h"

class UnequipCommand : public Command
{
public:
	UnequipCommand();
	~UnequipCommand();
	void Do(Player* i_player);
};

#endif // _UNEQUIPCOMMAND_INCLUDE
