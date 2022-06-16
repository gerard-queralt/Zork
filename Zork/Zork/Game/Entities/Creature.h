#ifndef _CREATURE_INCLUDE
#define _CREATURE_INCLUDE

#include "Room.h"

class Creature
{
public:
	Creature();
	~Creature();

private:
	Room* location;
};

#endif // _CREATURE_INCLUDE
