#ifndef _ROOM_INCLUDE
#define _ROOM_INCLUDE

#include "Entity.h"

class Room : Entity
{
public:
	Room();
	~Room();

	void Look() const;
};

#endif // _ROOM_INCLUDE