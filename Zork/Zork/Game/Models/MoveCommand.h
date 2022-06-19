#ifndef _MOVECOMMAND_INCLUDE
#define _MOVECOMMAND_INCLUDE

#include "Command.h"
#include "../Enumerations.h"

class MoveCommand : public Command
{
public:
	MoveCommand(Direction i_direction);
	~MoveCommand();

	void Do(Player* i_player);

private:
	Direction m_direction;
};

#endif // _MOVECOMMAND_INCLUDE
