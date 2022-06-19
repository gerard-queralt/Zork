#include "TrollBoss.h"

TrollBoss::TrollBoss(const string& i_name, const string& i_description, Room* i_location) : NPC(i_name, i_description, i_location, 50) //no need to set maxHP externally
{
}

TrollBoss::~TrollBoss()
{
}
