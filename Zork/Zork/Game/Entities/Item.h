#ifndef _ITEM_INCLUDE
#define _ITEM_INCLUDE

#include "Entity.h"

class Item : public Entity
{
public:
	Item(const string& name, const string& description);
	~Item();
};

#endif // _ITEM_INCLUDE
