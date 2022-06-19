#ifndef _ENTITY_INCLUDE
#define _ENTITY_INCLUDE

#include <string>
#include <list>
#include "../Enumerations.h"
using namespace std;

class Entity
{
public:
	Entity(const string& i_name, const string& i_description);
	~Entity();
	virtual void Update();

	virtual void Look() const;

	string GetName();
	EntityType GetType();
	virtual void AddEntity(Entity* i_entity);
	virtual bool Contains(Entity* i_entity);
	virtual Entity* RemoveEntity(Entity* i_entity);

protected:
	string m_name;
	string m_description;
	EntityType m_type;
	list<Entity*> m_contains;
};

#endif // _ENTITY_INCLUDE
