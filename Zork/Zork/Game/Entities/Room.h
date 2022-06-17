#ifndef _ROOM_INCLUDE
#define _ROOM_INCLUDE

#include "Entity.h"
#include "../Enumerations.h"

class Room : public Entity
{
public:
	Room(const string& name, const string& description);
	~Room();

	void Look() const;

	Room* getRoomInDirection(Direction direction);
};

#endif // _ROOM_INCLUDE