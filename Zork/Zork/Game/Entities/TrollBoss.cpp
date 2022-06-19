#include "TrollBoss.h"

TrollBoss::TrollBoss(const string& name, const string& description, Room* location) : NPC(name, description, location, 50) //no need to set maxHP externally
{
}

TrollBoss::~TrollBoss()
{
}
