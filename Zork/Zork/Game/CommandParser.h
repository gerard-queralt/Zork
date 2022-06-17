#ifndef _COMMANDPARSER_INCLUDE
#define _COMMANDPARSER_INCLUDE

#include <map>
#include <vector>
#include "Models/Command.h"
using namespace std;

class CommandParser
{
public:
	static Command* ParseCommand(const string& args);

private:
	static vector<string> SplitString(const string& text);

	static map<string, Direction> directionShorthands;
};

#endif // _COMMANDPARSER_INCLUDE
