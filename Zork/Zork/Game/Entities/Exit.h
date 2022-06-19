#ifndef _EXIT_INCLUDE
#define _EXIT_INCLUDE

#include <map>
#include <list>
#include "Entity.h"
#include "Room.h"

class Exit : public Entity
{
public:
	Exit(const string& name, const string& description, Direction direction, Room* from, Room* to);
	~Exit();

	void Look() const;

	Direction GetDirection();
	Room* GetRoomFrom(Room* from);
	void AddSelfToRooms();
	Exit* Reverse();
	void LockWith(const string& keyName);
	bool Unlock(const list<Entity*>& inventory);
	bool IsLocked();

private:
	static map<Direction, string> directionName;
	Direction direction;
	Room* from;
	Room* to;
	bool locked;
	string keyName;
};

#endif // _EXIT_INCLUDE
