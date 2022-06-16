#include "World.h"
#include <iostream>

#include "GameLoader.h"

World::World()
{
	entities = GameLoader::LoadEntities(&player);
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
