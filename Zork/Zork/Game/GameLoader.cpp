#include "GameLoader.h"
#include "EntityFinder.h"
#include "Entities/TrollBoss.h"

//ideally, this class would read json-like data, but for this small version it can all be instantiated "by hand"

GameLoader::LoadedResult GameLoader::LoadEntities()
{
    vector<Entity*> entities;

    Player* player = new Player();
    entities.push_back(player);

    vector<Item*> items = LoadItems();
    entities.insert(entities.end(), items.begin(), items.end());

    vector<Room*> rooms = LoadRooms(entities);
    entities.insert(entities.end(), rooms.begin(), rooms.end());

    vector<Exit*> exits = LoadExits(entities);
    entities.insert(entities.end(), exits.begin(), exits.end());

    vector<Npc*> npcs = LoadNPCs(entities);
    entities.insert(entities.end(), npcs.begin(), npcs.end());

    Entity* westHouse = EntityFinder::FindEntityByName("West of House", entities);
    player->Enter((Room*)westHouse);

    LoadedResult result;
    result.o_player = player;
    result.o_entities = entities;

    return result;
}

vector<Item*> GameLoader::LoadItems()
{
    vector<Item*> items;

    Item* houseKey = new Item("Key", "a small key.", true, false, 0);
    Item* keyChest = new Item("Chest", "a small chest with its lid ajar.", false, true, 0);
    keyChest->AddEntity(houseKey);
    keyChest->Close();
    Item* knife = new Item("Knife", "a kitchen knife.", true, false, 5);
    Item* rune = new Item("Stone", "an odd stone with weird markings.", true, false, 1);
    Item* club = new Item("Club", "a wooden club with some bloodstains.", true, false, 8);
    Item* axe = new Item("Axe", "an huge double-edged axe.", true, false, 100);
    Item* sword = new Item("Sword", "a sword with stones carved over it.", true, false, 20);

    items.push_back(houseKey);
    items.push_back(keyChest);
    items.push_back(knife);
    items.push_back(rune);
    items.push_back(club);
    items.push_back(axe);
    items.push_back(sword);

    return items;
}

vector<Room*> GameLoader::LoadRooms(const vector<Entity*>& i_existingEntities)
{
    vector<Room*> rooms;

    Room* westHouse = new Room("West of House", "This is an open field west of a white house.");

    Room* forest = new Room("Forest", "This is a forest, with trees in all directions around you.\nYou feel like you shouldn't go further.");
    Entity* keyChest = EntityFinder::FindEntityByName("Chest", i_existingEntities);
    forest->AddEntity(keyChest);

    Room* house = new Room("House", "You are in the living room of the house.");
    Entity* knife = EntityFinder::FindEntityByName("Knife", i_existingEntities);
    house->AddEntity(knife);

    Room* cellar = new Room("Cellar", "You are in a dark and damp cellar.");

    Room* ancientRoom = new Room("Weird room", "You are in a room noone has entered in years. The cobwebs covering the walls almost prevent you from seeing strange symbols and drawings on them.");
    Entity* sword = EntityFinder::FindEntityByName("Sword", i_existingEntities);
    ancientRoom->AddEntity(sword);

    Room* smallCave = new Room("Small cave", "You are in a narrow room barely lit by the light coming from the house above.");

    Room* trollRoom = new Room("The Troll room", "You are in a tall and spacious room. Some natural light filters from the ceiling avobe. Bloodstains and deep scratches mar the walls.");

    rooms.push_back(westHouse);
    rooms.push_back(forest);
    rooms.push_back(house);
    rooms.push_back(cellar);
    rooms.push_back(ancientRoom);
    rooms.push_back(smallCave);
    rooms.push_back(trollRoom);

    return rooms;
}

vector<Exit*> GameLoader::LoadExits(const vector<Entity*>& i_existingEntities)
{
    vector<Exit*> exits;

    Entity* westHouse = EntityFinder::FindEntityByName("West of House", i_existingEntities);
    Entity* forest = EntityFinder::FindEntityByName("Forest", i_existingEntities);
    Entity* house = EntityFinder::FindEntityByName("House", i_existingEntities);
    Entity* cellar = EntityFinder::FindEntityByName("Cellar", i_existingEntities);
    Entity* ancientRoom = EntityFinder::FindEntityByName("Weird room", i_existingEntities);
    Entity* smallCave = EntityFinder::FindEntityByName("Small cave", i_existingEntities);
    Entity* trollRoom = EntityFinder::FindEntityByName("The Troll room", i_existingEntities);
    
    if (westHouse->GetType() == ROOM && forest->GetType() == ROOM) {
        Exit* westToForest = new Exit("Entrance Forest", "There is a faded path between two trees.", WEST, (Room*)westHouse, (Room*)forest);
        westToForest->AddSelfToRooms();
        exits.push_back(westToForest);
    }
    
    if (westHouse->GetType() == ROOM && house->GetType() == ROOM) {
        Exit* westToHouse = new Exit("House door", "There is a door with an ornate keyhole.", EAST, (Room*)westHouse, (Room*)house);
        westToHouse->AddSelfToRooms();
        westToHouse->LockWith("Key");
        exits.push_back(westToHouse);
    }

    if (house->GetType() == ROOM && ancientRoom->GetType() == ROOM) {
        Exit* ancientDoor = new Exit("Ancient door", "The door is made of oak and has hollow shape where the lock should be.", SOUTH, (Room*)house, (Room*)ancientRoom);
        ancientDoor->AddSelfToRooms();
        ancientDoor->LockWith("Stone");
        exits.push_back(ancientDoor);
    }

    if (house->GetType() == ROOM && cellar->GetType() == ROOM) {
        Exit* trapdoor = new Exit("Trap-door", "There is a trap-door on the floor.", DOWN, (Room*)house, (Room*)cellar);
        trapdoor->AddSelfToRooms();
        exits.push_back(trapdoor);
    }

    if (cellar->GetType() == ROOM && smallCave->GetType() == ROOM) {
        Exit* caveEntrance = new Exit("Cave entrance", "There is a hole in the wall, big enough for you to fit through.", WEST, (Room*)cellar, (Room*)smallCave);
        caveEntrance->AddSelfToRooms();
        exits.push_back(caveEntrance);
    }

    if (cellar->GetType() == ROOM && trollRoom->GetType() == ROOM) {
        Exit* trollEntrance = new Exit("Troll Room entrance", "There is an ominous arch carved in the wall.", NORTH, (Room*)cellar, (Room*)trollRoom);
        trollEntrance->AddSelfToRooms();
        exits.push_back(trollEntrance);
    }

    return exits;
}

vector<Npc*> GameLoader::LoadNPCs(const vector<Entity*>& i_existingEntities)
{
    vector<Npc*> npcs;

    Creature* player = (Creature*)EntityFinder::FindEntityByName("Hero", i_existingEntities);

    Entity* smallCave = EntityFinder::FindEntityByName("Small cave", i_existingEntities);

    if (smallCave->GetType() == ROOM) {
        Npc* smallTroll = new Npc("Troll", "a troll of similar height to yours.", (Room*)smallCave, 10);
        Entity* rune = EntityFinder::FindEntityByName("Stone", i_existingEntities);
        Entity* club = EntityFinder::FindEntityByName("Club", i_existingEntities);
        smallTroll->AddEntity(rune);
        smallTroll->AddEntity(club);
        smallTroll->SetWeapon((Item*)club);
        smallTroll->SetCombatTarget(player);
        npcs.push_back(smallTroll);
    }

    Entity* trollRoom = EntityFinder::FindEntityByName("The Troll room", i_existingEntities);

    if (trollRoom->GetType() == ROOM) {
        Npc* trollBoss = new TrollBoss((Room*)trollRoom);
        Entity* axe = EntityFinder::FindEntityByName("Axe", i_existingEntities);
        trollBoss->AddEntity(axe);
        trollBoss->SetWeapon((Item*)axe);
        trollBoss->SetCombatTarget(player);
        npcs.push_back(trollBoss);
    }

    return npcs;
}
