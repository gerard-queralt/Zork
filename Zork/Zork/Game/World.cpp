#include "World.h"
#include <iostream>

#include "GameLoader.h"
#include "Models/Command.h"

World::World()
{
	GameLoader::LoadedResult loadData = GameLoader::LoadEntities();
	m_entities = loadData.o_entities;
	m_player = loadData.o_player;
	m_parser = new CommandParser(m_entities);
}

World::~World()
{
	for (Entity* entity : m_entities) {
		delete entity;
	}
	m_entities.clear();
}

void World::Update(const string& i_args)
{
	for (Entity* entity : m_entities) {
		entity->Update();
	}
	Command* command = m_parser->ParseCommand(i_args);
	if (command != NULL && !m_player->IsDead()) {
		command->Do(m_player);
		delete command;
	}
}
