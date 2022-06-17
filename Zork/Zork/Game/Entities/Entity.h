#ifndef _ENTITY_INCLUDE
#define _ENTITY_INCLUDE

#include <string>
#include <list>
#include "../Enumerations.h"
using namespace std;

class Entity
{
public:
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
