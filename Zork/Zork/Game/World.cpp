#include "World.h"
#include <iostream>

#include "GameLoader.h"

World::World()
{
	GameLoader::LoadedResult loadData = GameLoader::LoadEntities();
	entities = loadData.entities;
	player = loadData.player;
}

World::~World()
{
	for (Entity* entity : entities) {
		delete entity;
	}
	entities.clear();
}

void World::Update(const string& args)
{
	for (Entity* entity : entities) {
		entity->Update();
	}
}
