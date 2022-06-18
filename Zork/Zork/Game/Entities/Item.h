#ifndef _ITEM_INCLUDE
#define _ITEM_INCLUDE

#include "Entity.h"

class Item : public Entity
{
public:
	Item(const string& name, const string& description, bool canBePicked, bool canBeClosed);
	~Item();

	void Look() const;

	bool Contains(Entity* entity);

	bool CanBePicked();

	void Close();
	void Open();

private:
	void LookContents() const;

	bool canBePicked;
	bool canBeClosed;
	bool closed;
};

#endif // _ITEM_INCLUDE
