#ifndef _MOVECOMMAND_INCLUDE
#define _MOVECOMMAND_INCLUDE

#include "Command.h"
#include "../Enumerations.h"

class MoveCommand : public Command
{
public:
	MoveCommand(Direction direction);
	~MoveCommand();

	void Do(Player* player);

private:
	Direction direction;
};

#endif // _MOVECOMMAND_INCLUDE
