#ifndef _COMMAND_INCLUDE
#define _COMMAND_INCLUDE

#include "../Entities/Player.h"

class Command
{
public:
	virtual void Do(Player* i_player) = 0;
};

#endif // _ENTITY_INCLUDE
