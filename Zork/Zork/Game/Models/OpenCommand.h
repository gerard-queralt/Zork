#ifndef _OPENCOMMAND_INCLUDE
#define _OPENCOMMAND_INCLUDE

#include "Command.h"

class OpenCommand : public Command
{
public:
	OpenCommand(Item* i_target);
	~OpenCommand();
	void Do(Player* i_player);

private:
	Item* m_target;
};

#endif // _OPENCOMMAND_INCLUDE
