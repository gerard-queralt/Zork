#ifndef _PUTCOMMAND_INCLUDE
#define _PUTCOMMAND_INCLUDE

#include "Command.h"

class PutCommand : public Command
{
public:
	PutCommand(Item* target, Item* container);
	~PutCommand();
	void Do(Player* player);

private:
	Item* target;
	Item* container;
};

#endif // _PUTCOMMAND_INCLUDE
