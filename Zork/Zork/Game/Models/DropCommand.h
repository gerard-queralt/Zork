#ifndef _DROPCOMMAND_INCLUDE
#define _DROPCOMMAND_INCLUDE

#include "Command.h"
#include "../Entities/Item.h"

class DropCommand : public Command
{
public:
	DropCommand(Item* i_target);
	~DropCommand();
	void Do(Player* i_player);

private:
	Item* m_target;
};

#endif // _DROPCOMMAND_INCLUDE
