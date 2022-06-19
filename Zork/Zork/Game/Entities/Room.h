#ifndef _ROOM_INCLUDE
#define _ROOM_INCLUDE

#include <list>
#include "Entity.h"
#include "../Enumerations.h"
using namespace std;

class Room : public Entity
{
public:
	Room(const string& i_name, const string& i_description);
	~Room();

	void Look() const;

	bool Contains(Entity* i_entity);
	Entity* RemoveEntity(Entity* i_entity);

	Room* AccessRoomInDirection(Direction i_direction, const list<Entity*>& i_playerInventory);
};

#endif // _ROOM_INCLUDE