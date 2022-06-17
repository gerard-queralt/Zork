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
		EXIT,
		ITEM,
		CREATURE,
		PLAYER,
		NUM_TYPES
	};

	Entity(const string &name, const string &description);
	~Entity();
	virtual void Update();

	virtual void Look() const;

	string getName();
	EntityType getType();
	void AddEntity(Entity* entity);

protected:
	string name;
	string description;
	EntityType type;
	list<Entity*> contains;
};

#endif // _ENTITY_INCLUDE
