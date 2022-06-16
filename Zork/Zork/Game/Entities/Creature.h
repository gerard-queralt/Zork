#ifndef _CREATURE_INCLUDE
#define _CREATURE_INCLUDE

#include "Entity.h"
#include "Room.h"

class Creature : Entity
{
public:
	Creature(const string& name, const string& description);
	~Creature();

private:
	Room* location;
};

#endif // _CREATURE_INCLUDE
