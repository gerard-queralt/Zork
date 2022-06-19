#ifndef _NPC_INCLUDE
#define _NPC_INCLUDE

#include "Creature.h"
#include "Item.h"

class NPC : public Creature
{
public:
	NPC(const string& i_name, const string& i_description, Room* i_location, int i_maxHP);
	~NPC();
};

#endif // _NPC_INCLUDE
