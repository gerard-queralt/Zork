#ifndef _OPENCOMMAND_INCLUDE
#define _OPENCOMMAND_INCLUDE

#include "Command.h"

class OpenCommand : public Command
{
public:
	OpenCommand(Item* target);
	~OpenCommand();
	void Do(Player* player);

private:
	Item* target;
};

#endif // _OPENCOMMAND_INCLUDE
