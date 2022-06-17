#include "GetCommand.h"
#include <iostream>

GetCommand::GetCommand(Item* target)
{
	this->target = target;
}

GetCommand::~GetCommand()
{
}

void GetCommand::Do(Player* player)
{
	if (player->getLocation()->EntityInRoom(target->getName())) {
		player->AddEntity(target);
		cout << "Taken." << endl;
	}
	else {
		cout << "That's not an item in this room." << endl;
	}
}
