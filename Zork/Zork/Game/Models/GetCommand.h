#ifndef _GETCOMMAND_INCLUDE
#define _GETCOMMAND_INCLUDE

#include "Command.h"
#include "../Entities/Item.h"

class GetCommand : public Command
{
public:
	GetCommand(Item* target);
	~GetCommand();
	void Do(Player* player);

private:
	Item* target;
};

#endif // _GETCOMMAND_INCLUDE
