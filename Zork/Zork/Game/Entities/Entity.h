#ifndef _ENTITY_INCLUDE
#define _ENTITY_INCLUDE

#include <string>
#include <list>
using namespace std;

class Entity
{
public:
	enum EntityType {
		NUM_TYPES
	};

	Entity();
	~Entity();
	virtual void Update();

protected:
	string name;
	string description;
	list<Entity*> contains;
};

#endif // _ENTITY_INCLUDE
