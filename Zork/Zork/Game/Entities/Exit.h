#ifndef _EXIT_INCLUDE
#define _EXIT_INCLUDE

#include "Entity.h"
#include "Room.h"

enum Direction {
	NORTH = 0,
	SOUTH,
	EAST,
	WEST,
	NUM_DIRECTIONS
};

class Exit : public Entity
{
public:
	Exit(const string& name, const string& description, Direction direction, Room* from, Room* to);
	~Exit();

private:
	Exit* Reverse();
	void AddSelfToRooms();

	Direction direction;
	Room* from;
	Room* to;
};

#endif // _EXIT_INCLUDE
