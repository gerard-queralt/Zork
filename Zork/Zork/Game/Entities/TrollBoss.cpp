#include "TrollBoss.h"
#include <iostream>

TrollBoss::TrollBoss(Room* i_location) : 
	Npc("Boss", "a giant troll covered in scars.\n(To target it with an attack, please refer to it as \"boss\")", i_location, 50) //no need to set attributes externally
{
	m_instaDeathCountdown = 3;
}

TrollBoss::~TrollBoss()
{
}

void TrollBoss::Update()
{
	if (CanAttackTarget()) {
		switch (m_instaDeathCountdown)
		{
		case 3:
			cout << "The giant troll glances at you, and begins moving slowly." << endl;
			break;
		case 2:
			cout << "The troll starts raising its axe." << endl;
			break;
		case 1:
			cout << "The axe is fully raised above the monster's head." << endl;
			break;
		case 0:
			cout << "The troll brings its giant axe down, cutting you cleanly in half." << endl;
			AttackTargetWithWeapon();
			break;
		default:
			break;
		}
		--m_instaDeathCountdown;
	}
}

void TrollBoss::Die()
{
	cout << "The beast falls to the ground, dead." << endl;
	m_dead = true;
	cout << "You did it! You can explore the rest of the dungeon now... If there was any." << endl;
	cout << "Thanks for playong! Be sure to check out the original Zork if you enjoyed this small tribute!" << endl;
}
