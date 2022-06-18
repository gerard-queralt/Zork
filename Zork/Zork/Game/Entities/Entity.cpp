#include <iostream>
#include "Entity.h"

Entity::Entity(const string& name, const string& description)
{
	this->name = name;
	this->description = description;
	this->type = ENTITY;
}

Entity::~Entity()
{
}

void Entity::Update()
{
}

void Entity::Look() const
{
	std::cout << description << endl;
}

string Entity::getName()
{
	return name;
}

EntityType Entity::getType()
{
	return type;
}

void Entity::AddEntity(Entity* entity)
{
	if (entity != NULL) {
		contains.push_back(entity);
	}
}

bool Entity::Contains(Entity* entity)
{
	return find(contains.begin(), contains.end(), entity) != contains.end();
}

Entity* Entity::RemoveEntity(Entity* entity)
{
	if (Contains(entity)) {
		contains.remove(entity);
		return entity;
	}
	return NULL;
}
