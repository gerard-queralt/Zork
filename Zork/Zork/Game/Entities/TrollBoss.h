#ifndef _TROLLBOSS_INCLUDE
#define _TROLLBOSS_INCLUDE

#include "NPC.h"

class TrollBoss : public NPC
{
	TrollBoss(const string& i_name, const string& i_description, Room* i_location);
	~TrollBoss();
};

#endif // _TROLLBOSS_INCLUDE
