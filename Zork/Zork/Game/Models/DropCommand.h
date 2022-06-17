#ifndef _DROPCOMMAND_INCLUDE
#define _DROPCOMMAND_INCLUDE

#include "Command.h"
#include "../Entities/Item.h"

class DropCommand : public Command
{
public:
	DropCommand(Item* target);
	~DropCommand();
	void Do(Player* player);

private:
	Item* target;
};

#endif // _DROPCOMMAND_INCLUDE
