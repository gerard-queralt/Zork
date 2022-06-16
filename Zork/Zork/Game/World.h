#ifndef _WORLD_INCLUDE
#define _WORLD_INCLUDE

#include <vector>
#include "Entities/Entity.h"
using namespace std;

class World
{
public:
	void Init();
	void Update();
private:
	vector<Entity*> entities;
};

#endif // _WORLD_INCLUDE
