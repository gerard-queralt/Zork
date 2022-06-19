#include <iostream>
#include "Entity.h"

Entity::Entity(const string& i_name, const string& i_description)
{
	m_name = i_name;
	m_description = i_description;
	m_type = ENTITY;
}

Entity::~Entity()
{
}

void Entity::Update()
{
}

void Entity::Look() const
{
	std::cout << m_description << endl;
}

string Entity::GetName()
{
	return m_name;
}

EntityType Entity::GetType()
{
	return m_type;
}

void Entity::AddEntity(Entity* i_entity)
{
	if (i_entity != NULL) {
		m_contains.push_back(i_entity);
	}
}

bool Entity::Contains(Entity* i_entity)
{
	return find(m_contains.begin(), m_contains.end(), i_entity) != m_contains.end();
}

Entity* Entity::RemoveEntity(Entity* i_entity)
{
	if (Contains(i_entity)) {
		m_contains.remove(i_entity);
		return i_entity;
	}
	return NULL;
}
