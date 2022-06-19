#ifndef _EXIT_INCLUDE
#define _EXIT_INCLUDE

#include <map>
#include <list>
#include "Entity.h"
#include "Room.h"

class Exit : public Entity
{
public:
	Exit(const string& i_name, const string& i_description, Direction i_direction, Room* i_from, Room* i_to);
	~Exit();

	void Look() const;

	Direction GetDirection();
	Room* GetRoomFrom(Room* i_from);
	void AddSelfToRooms();
	Exit* Reverse();
	void LockWith(const string& i_keyName);
	bool Unlock(const list<Entity*>& i_inventory);
	bool IsLocked();

private:
	static map<Direction, string> s_directionName;
	Direction m_direction;
	Room* m_from;
	Room* m_to;
	bool m_locked;
	string m_keyName;
};

#endif // _EXIT_INCLUDE
