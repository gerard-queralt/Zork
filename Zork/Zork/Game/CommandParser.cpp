#include "CommandParser.h"

#include <iostream>
#include "Models/MoveCommand.h"
#include "Models/GetCommand.h"
#include "Models/DropCommand.h"
#include "Models/OpenCommand.h"
#include "Models/LookCommand.h"
#include "Models/InventoryCommand.h"
#include "Models/PutCommand.h"
#include "Models/AttackCommand.h"
#include "Models/EquipCommand.h"
#include "Models/UnequipCommand.h"
#include "EntityFinder.h"
#include "Entities/Item.h"
#include "Entities/Npc.h"

map<string, Direction> CommandParser::s_directionShorthands = {
	{"north", NORTH},
	{"n", NORTH},
	{"south", SOUTH},
	{"s", SOUTH},
	{"east", EAST},
	{"e", EAST},
	{"west", WEST},
	{"w", WEST},
	{"up", UP},
	{"u", UP},
	{"down", DOWN},
	{"d", DOWN}
};

CommandParser::CommandParser(const vector<Entity*>& i_worldEntities)
{
	m_worldEntities = i_worldEntities;
}

CommandParser::~CommandParser()
{
}

Command* CommandParser::ParseCommand(const string& i_args)
{
	vector<string> split = SplitString(i_args);

	if (!split.empty()) {
		//all the conditions below could be better grouped to be more efficient, but I think it's more readable

		//check if move command
		if (split.size() == 1 && s_directionShorthands.find(split[0]) != s_directionShorthands.end()) {
			Direction direction = s_directionShorthands[split[0]];
			return new MoveCommand(direction);
		}
		else if (split.size() == 2 && (split[0] == "move" || split[0] == "go")) {
			if (s_directionShorthands.find(split[1]) != s_directionShorthands.end()) {
				Direction direction = s_directionShorthands[split[1]];
				return new MoveCommand(direction);
			}
			cout << "That's not a valid direction." << endl;
			return NULL;
		}

		//check if get command
		if (split.size() == 2 && (split[0] == "get" || split[0] == "take")) {
			Entity* eTarget = FindTarget(split[1]);
			if (eTarget != NULL && eTarget->GetType() == ITEM) {
				Item* target = (Item*)eTarget;
				return new GetCommand(target);
			}
			cout << "That's not an item." << endl;
			return NULL;
			
		}

		//check if drop command
		if (split.size() == 2 && split[0] == "drop") {
			Entity* eTarget = FindTarget(split[1]);
			if (eTarget != NULL && eTarget->GetType() == ITEM) {
				Item* target = (Item*)eTarget;
				return new DropCommand(target);
			}
			cout << "That's not an item." << endl;
			return NULL;
		}

		//check if open command
		if (split.size() == 2 && split[0] == "open") {
			Entity* eTarget = FindTarget(split[1]);
			if (eTarget != NULL && eTarget->GetType() == ITEM) {
				Item* target = (Item*)eTarget;
				return new OpenCommand(target);
			}
			cout << "That's not an item." << endl;
			return NULL;
		}

		//check if look command
		if (split.size() == 1 && split[0] == "look") {
			return new LookCommand();
		}
		
		//check if inventory command
		if (split.size() == 1 && (split[0] == "inventory" || split[0] == "i")) {
			return new InventoryCommand();
		}

		//check if put command
		if (split.size() == 4 && (split[0] == "put" && split[2] == "in")) {
			Entity* eTarget = FindTarget(split[1]);
			Entity* eContainer = FindTarget(split[3]);
			if (eTarget != NULL && eTarget->GetType() == ITEM && eContainer != NULL && eContainer->GetType() == ITEM) {
				Item* target = (Item*)eTarget;
				Item* container = (Item*)eContainer;
				return new PutCommand(target, container);
			}
			cout << "That's not an item." << endl;
			return NULL;
		}

		//check if attack command
		if ((split.size() == 2 || split.size() == 4) && split[0] == "attack") {
			Entity* eTarget = FindTarget(split[1]);
			if (eTarget != NULL && eTarget->GetType() == NPC) {
				Npc* target = (Npc*)eTarget;
				if (split.size() == 4 && split[2] == "with") {
					Entity* eWeapon = FindTarget(split[3]);
					if (eWeapon != NULL && eWeapon->GetType() == ITEM){
						Item* weapon = (Item*)eWeapon;
						return new AttackCommand(target, weapon);
					}
					cout << "That's not an item." << endl;
					return NULL;
				}
				return new AttackCommand(target);
			}
			cout << "That's not an enemy." << endl;
			return NULL;
		}

		//check if equip command
		if (split.size() == 2 && split[0] == "equip") {
			Entity* eTarget = FindTarget(split[1]);
			if (eTarget != NULL && eTarget->GetType() == ITEM) {
				Item* target = (Item*)eTarget;
				return new EquipCommand(target);
			}
			cout << "That's not an item." << endl;
			return NULL;
		}

		//check if unequip command
		if (split.size() == 1 && split[0] == "unequip") {
			return new UnequipCommand();
		}
	}

	cout << "Sorry, I didn't understand that." << endl;
	return NULL;
}

vector<string> CommandParser::SplitString(const string& i_text)
{
	vector<string> words;
	string word = "";
	for (int c = 0; c < i_text.size(); ++c) {
		char charAtC = i_text[c];
		if (charAtC != ' ') {
			word.push_back(charAtC);
		}
		else if (!word.empty()) {
			words.push_back(word);
			word = "";
		}
	}
	if (!word.empty()) {
		words.push_back(word);
	}
	return words;
}

Entity* CommandParser::FindTarget(string& i_targetName)
{
	i_targetName[0] = toupper(i_targetName[0]); //allow name in lowercase
	return EntityFinder::FindEntityByName(i_targetName, m_worldEntities);
}
