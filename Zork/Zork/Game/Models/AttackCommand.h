#ifndef _ATTACKCOMMAND_INCLUDE
#define _ATTACKCOMMAND_INCLUDE

#include "Command.h"
#include "..\Entities\Creature.h"
#include "..\Entities\Item.h"

class AttackCommand : public Command
{
public:
	AttackCommand(Creature* i_target);
	AttackCommand(Creature* i_target, Item* i_weapon);
	~AttackCommand();
	void Do(Player* i_player);

private:
	Creature* m_target;
	Item* m_weapon;
};

#endif // _ATTACKCOMMAND_INCLUDE
