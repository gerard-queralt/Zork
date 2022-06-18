#include "Item.h"
#include <iostream>

Item::Item(const string& name, const string& description, bool canBePicked, bool canBeClosed) : Entity(name, description)
{
	this->type = ITEM;
	this->canBePicked = canBePicked;
	this->canBeClosed = canBeClosed;
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
	if (canBeClosed) {
		closed = true;
	}
}

void Item::Open()
{
	if (canBeClosed) {
		if (closed) {
			closed = false;
		}
		else {
			cout << "It's already open." << endl;
		}
	}
	else {
		cout << "You can't open or close that." << endl;
	}
}
