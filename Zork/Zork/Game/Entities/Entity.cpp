#include <iostream>
#include "Entity.h"

Entity::Entity()
{
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
