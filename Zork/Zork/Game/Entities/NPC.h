#ifndef _NPC_INCLUDE
#define _NPC_INCLUDE

#include "Creature.h"
#include "Item.h"

class Npc : public Creature
{
public:
	Npc(const string& i_name, const string& i_description, Room* i_location, int i_maxHP);
	~Npc();
	virtual void Update();
};

#endif // _NPC_INCLUDE
