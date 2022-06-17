#ifndef _COMMANDPARSER_INCLUDE
#define _COMMANDPARSER_INCLUDE

#include <map>
#include <vector>
#include "Models/Command.h"
using namespace std;

class CommandParser
{
public:
	CommandParser(const vector<Entity*>& worldEntities);
	~CommandParser();
	Command* ParseCommand(const string& args);

private:
	vector<string> SplitString(const string& text);

	static map<string, Direction> directionShorthands;
	vector<Entity*> worldEntities;
};

#endif // _COMMANDPARSER_INCLUDE
