#ifndef _LOOKCOMMAND_INCLUDE
#define _LOOKCOMMAND_INCLUDE

#include "Command.h"

class LookCommand : public Command
{
public:
	LookCommand();
	~LookCommand();
	
	void Do(Player* player);
};

#endif // _LOOKCOMMAND_INCLUDE
