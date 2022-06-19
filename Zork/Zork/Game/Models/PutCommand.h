#ifndef _PUTCOMMAND_INCLUDE
#define _PUTCOMMAND_INCLUDE

#include "Command.h"

class PutCommand : public Command
{
public:
	PutCommand(Item* i_target, Item* i_container);
	~PutCommand();
	void Do(Player* i_player);

private:
	Item* m_target;
	Item* m_container;
};

#endif // _PUTCOMMAND_INCLUDE
