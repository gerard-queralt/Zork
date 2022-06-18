#ifndef _ITEM_INCLUDE
#define _ITEM_INCLUDE

#include "Entity.h"

class Item : public Entity
{
public:
	Item(const string& name, const string& description, bool canBePicked);
	~Item();

	void Look() const;

	bool CanBePicked();

	void Close();
	void Open();

private:
	bool canBePicked;
	bool closed;
};

#endif // _ITEM_INCLUDE
