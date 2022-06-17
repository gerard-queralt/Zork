#ifndef _CREATURE_INCLUDE
#define _CREATURE_INCLUDE

#include "Entity.h"
#include "Room.h"

class Creature : public Entity
{
public:
	Creature(const string& name, const string& description, Room* location);
	~Creature();

	virtual void Enter(Room* room);

protected:
	Room* location;
};

#endif // _CREATURE_INCLUDE
