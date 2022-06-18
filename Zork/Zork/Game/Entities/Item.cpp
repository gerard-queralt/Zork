#include "Item.h"
#include <iostream>

Item::Item(const string& name, const string& description, bool canBePicked) : Entity(name, description)
{
	this->type = ITEM;
	this->canBePicked = canBePicked;
	this->closed = false;
}

Item::~Item()
{
}

void Item::Look() const
{
	Entity::Look();
	if (!contains.empty() && !closed) {
		cout << "Inside of it are:" << endl;
		for (Entity* entity : contains) {
			cout << "\t";
			entity->Look();
		}
	}
}

bool Item::CanBePicked()
{
	return canBePicked;
}

void Item::Close()
{
	closed = true;
}

void Item::Open()
{
	closed = false;
}
