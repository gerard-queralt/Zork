#include "World.h"

void World::Init()
{
}

void World::Update()
{
	for (Entity* entity : entities) {
		entity->Update();
	}
}
