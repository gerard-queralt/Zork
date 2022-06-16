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
