#ifndef _GETCOMMAND_INCLUDE
#define _GETCOMMAND_INCLUDE

#include "Command.h"
#include "../Entities/Item.h"

class GetCommand : public Command
{
public:
	GetCommand(Item* i_target);
	~GetCommand();
	void Do(Player* i_player);

private:
	Item* m_target;
};

#endif // _GETCOMMAND_INCLUDE
