#include "CommandParser.h"

#include <iostream>
#include "Models/MoveCommand.h"

map<string, Direction> CommandParser::directionShorthands = {
	{"north", NORTH},
	{"n", NORTH},
	{"south", SOUTH},
	{"s", SOUTH},
	{"east", EAST},
	{"e", EAST},
	{"west", WEST},
	{"w", WEST}
};

CommandParser::CommandParser(const vector<Entity*>& worldEntities)
{
	this->entities = worldEntities;
}

CommandParser::~CommandParser()
{
}

Command* CommandParser::ParseCommand(const string& args)
{
	vector<string> split = SplitString(args);

	if (!split.empty()) {
		//all the conditions below could be better grouped to be more efficient, but I think it's more readable

		//check if move command
		if (split.size() == 1 && directionShorthands.find(split[0]) != directionShorthands.end()) {
			Direction direction = directionShorthands[split[0]];
			return new MoveCommand(direction);
		}
		else if (split.size() == 2 && (split[0] == "move" || split[0] == "go")) {
			if (directionShorthands.find(split[1]) != directionShorthands.end()) {
				Direction direction = directionShorthands[split[1]];
				return new MoveCommand(direction);
			}
			cout << "That's not a valid direction." << endl;
			return NULL;
		}

		//check if get command
		if (split.size() == 2 && (split[0] == "get" || split[0] == "take")) {
			//WIP
		}
	}

	cout << "Sorry, I didn't understand that." << endl;
	return NULL;
}

vector<string> CommandParser::SplitString(const string& text)
{
	vector<string> words;
	string word = "";
	for (int c = 0; c < text.size(); ++c) {
		char charAtC = text[c];
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
