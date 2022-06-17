#ifndef _ITEM_INCLUDE
#define _ITEM_INCLUDE

#include "Entity.h"

class Item : public Entity
{
public:
	Item(const string& name, const string& description, bool canBePicked);
	~Item();

	bool CanBePicked();

private:
	bool canBePicked;
};

#endif // _ITEM_INCLUDE
