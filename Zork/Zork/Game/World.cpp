#include "World.h"
#include <iostream>

#include "GameLoader.h"
#include "CommandParser.h"
#include "Models/Command.h"

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
	Command* command = CommandParser::ParseCommand(args);
	if (command != NULL) {
		command->Do(player);
	}
}
