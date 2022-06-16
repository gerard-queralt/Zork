#ifndef _ENTITY_INCLUDE
#define _ENTITY_INCLUDE

#include <string>
#include <list>
using namespace std;

class Entity
{
public:
	enum EntityType {
		ENTITY = 0,
		ROOM,
		CREATURE,
		PLAYER,
		NUM_TYPES
	};

	Entity(const string &name, const string &description);
	~Entity();
	virtual void Update();

	virtual void Look() const;

protected:
	string name;
	string description;
	EntityType type;
	list<Entity*> contains;
};

#endif // _ENTITY_INCLUDE
