#include "Item.h"

Item::Item(const string& name, const string& description, bool canBePicked) : Entity(name, description)
{
	this->type = ITEM;
	this->canBePicked = canBePicked;
}

Item::~Item()
{
}

bool Item::CanBePicked()
{
	return canBePicked;
}
