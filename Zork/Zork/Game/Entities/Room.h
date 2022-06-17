#ifndef _ROOM_INCLUDE
#define _ROOM_INCLUDE

#include <list>
#include "Entity.h"
#include "../Enumerations.h"
using namespace std;

class Room : public Entity
{
public:
	Room(const string& name, const string& description);
	~Room();

	void Look() const;

	bool EntityInRoom(const string& entityName);
	Room* AccessRoomInDirection(Direction direction, const list<Entity*>& playerInventory);
};

#endif // _ROOM_INCLUDE