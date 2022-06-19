#include "Item.h"
#include <iostream>

Item::Item(const string& i_name, const string& i_description, bool i_canBePicked, bool i_canBeClosed, int i_damage) : Entity(i_name, i_description)
{
	m_canBePicked = i_canBePicked;
	m_canBeClosed = i_canBeClosed;
	m_damage = i_damage;
	m_closed = false;
	m_type = ITEM;
}

Item::~Item()
{
}

void Item::Look() const
{
	Entity::Look();
	LookContents();
}

void Item::AddEntity(Entity* i_entity)
{
	if (!m_closed) {
		Entity::AddEntity(i_entity);
	}
	else {
		cout << "You can't put that in there, it's closed." << endl;
	}
}

bool Item::Contains(Entity* i_entity)
{
	if (!m_closed) {
		return Entity::Contains(i_entity);
	}
	return false;
}

bool Item::CanBePicked()
{
	return m_canBePicked;
}

void Item::Close()
{
	if (m_canBeClosed) {
		m_closed = true;
	}
}

void Item::Open()
{
	if (m_canBeClosed) {
		if (m_closed) {
			m_closed = false;
			cout << "It opened." << endl;
			LookContents();
		}
		else {
			cout << "It's already open." << endl;
		}
	}
	else {
		cout << "You can't open or close that." << endl;
	}
}

int Item::GetDamage()
{
	return m_damage;
}

void Item::LookContents() const
{
	if (!m_contains.empty() && !m_closed) {
		cout << "Inside of it are:" << endl;
		for (Entity* entity : m_contains) {
			cout << "  ";
			entity->Look();
		}
	}
}
