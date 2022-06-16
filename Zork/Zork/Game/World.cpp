#include "World.h"
#include <iostream>

World::World()
{
}

World::~World()
{
	for (Entity* entity : entities) {
		delete entity;
	}
	entities.clear();
}

void World::Update()
{
	for (Entity* entity : entities) {
		entity->Update();
	}
}
