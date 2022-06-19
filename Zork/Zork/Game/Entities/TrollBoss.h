#ifndef _TROLLBOSS_INCLUDE
#define _TROLLBOSS_INCLUDE

#include "Npc.h"

class TrollBoss : public Npc
{
public:
	TrollBoss(Room* i_location);
	~TrollBoss();
	void Update();

protected:
	void Die();

private:
	int m_instaDeathCountdown;
};

#endif // _TROLLBOSS_INCLUDE
