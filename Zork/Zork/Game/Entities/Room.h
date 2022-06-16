#ifndef _ROOM_INCLUDE
#define _ROOM_INCLUDE

#include "Entity.h"

class Room : public Entity
{
public:
	Room(const string& name, const string& description);
	~Room();

	void Look() const;
};

#endif // _ROOM_INCLUDE