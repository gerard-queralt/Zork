#ifndef _EXIT_INCLUDE
#define _EXIT_INCLUDE

#include "Entity.h"
#include "Room.h"

class Exit : public Entity
{
public:
	enum Direction {
		NORTH = 0,
		SOUTH,
		EAST,
		WEST,
		NUM_DIRECTIONS
	};

	Exit(const string& name, const string& description, Direction direction, Room* from, Room* to);
	~Exit();

	Exit Reverse();

private:
	Direction direction;
	Room* from;
	Room* to;
};

#endif // _EXIT_INCLUDE
