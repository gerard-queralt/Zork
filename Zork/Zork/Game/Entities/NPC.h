#ifndef _NPC_INCLUDE
#define _NPC_INCLUDE

#include "Creature.h"
#include "Item.h"

class NPC : public Creature
{
public:
	NPC(const string& name, const string& description, Room* location);
	~NPC();
};

#endif // _NPC_INCLUDE
