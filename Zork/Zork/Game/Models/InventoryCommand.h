#ifndef _INVENTORYCOMMAND_INCLUDE
#define _INVENTORYCOMMAND_INCLUDE

#include "Command.h"

class InventoryCommand : public Command
{
public:
	InventoryCommand();
	~InventoryCommand();
	void Do(Player* player);
};

#endif // _INVENTORYCOMMAND_INCLUDE

