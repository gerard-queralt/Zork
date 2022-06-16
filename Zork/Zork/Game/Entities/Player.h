#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE

#include "Entity.h"

class Player : public Entity
{
	Player(const string& name, const string& description);
	~Player();
};

#endif // _PLAYER_INCLUDE
