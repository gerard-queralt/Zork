#ifndef _ITEM_INCLUDE
#define _ITEM_INCLUDE

#include "Entity.h"

class Item : public Entity
{
public:
	Item(const string& name, const string& description, bool canBePicked, bool canBeClosed, int damage);
	~Item();

	void Look() const;

	void AddEntity(Entity* entity);
	bool Contains(Entity* entity);

	bool CanBePicked();

	void Close();
	void Open();

private:
	void LookContents() const;

	bool canBePicked;
	bool canBeClosed;
	bool closed;
	int damage;
};

#endif // _ITEM_INCLUDE
