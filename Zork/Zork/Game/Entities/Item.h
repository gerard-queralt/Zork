#ifndef _ITEM_INCLUDE
#define _ITEM_INCLUDE

#include "Entity.h"

class Item : public Entity
{
public:
	Item(const string& i_name, const string& i_description, bool i_canBePicked, bool i_canBeClosed, int i_damage);
	~Item();

	void Look() const;

	void AddEntity(Entity* i_entity);
	bool Contains(Entity* i_entity);

	bool CanBePicked();

	void Close();
	void Open();

	int GetDamage();

private:
	void LookContents() const;

	bool m_canBePicked;
	bool m_canBeClosed;
	bool m_closed;
	int m_damage;
};

#endif // _ITEM_INCLUDE
