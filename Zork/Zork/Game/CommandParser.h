#ifndef _COMMANDPARSER_INCLUDE
#define _COMMANDPARSER_INCLUDE

#include <map>
#include <vector>
#include "Models/Command.h"
using namespace std;

class CommandParser
{
public:
	CommandParser(const vector<Entity*>& i_worldEntities);
	~CommandParser();
	Command* ParseCommand(const string& i_args);

private:
	vector<string> SplitString(const string& i_text);
	Entity* FindTarget(string& i_targetName);

	static map<string, Direction> s_directionShorthands;
	vector<Entity*> m_worldEntities;
};

#endif // _COMMANDPARSER_INCLUDE
