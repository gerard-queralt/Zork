#ifndef _TROLLBOSS_INCLUDE
#define _TROLLBOSS_INCLUDE

#include "NPC.h"

class TrollBoss : public NPC
{
	TrollBoss(const string& name, const string& description, Room* location);
	~TrollBoss();
};

#endif // _TROLLBOSS_INCLUDE
