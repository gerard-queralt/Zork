#include "Player.h"

#include <iostream>

Player::Player() : Creature("Hero", "That's you!", NULL, 25) //no need to set attributes externally
{
	m_type = PLAYER;
}

Player::~Player()
{
}

void Player::Look() const
{
	if (m_contains.empty()) {
		cout << "You have nothing on you." << endl;
	}
	else {
		if (m_weapon != NULL) {
			cout << "You have a " << m_weapon->GetName() << " equiped." << endl;
		}
		cout << "You have:" << endl;
		for (Entity* entity : m_contains) {
			cout << "  ";
			entity->Look();
		}
	}
}

void Player::Enter(Room* i_room)
{
	Creature::Enter(i_room);
	m_location->Look();
}

void Player::Move(Direction i_direction)
{
	Room* nextRoom = m_location->AccessRoomInDirection(i_direction, m_contains);
	if (nextRoom != NULL) {
		Enter(nextRoom);
	}
}

void Player::Get(Item* i_item)
{
	if (m_location->Contains(i_item)) {
		if (i_item->CanBePicked()) {
			this->AddEntity(m_location->RemoveEntity(i_item));
			cout << "Taken." << endl;
		}
		else {
			cout << "That can't be picked up." << endl;
		}
	}
	else {
		cout << "That's not an item in this room." << endl;
	}
}

void Player::Drop(Item* i_item)
{
	if (this->Contains(i_item)) {
		Creature::Drop(i_item);
		cout << "Dropped." << endl;
	}
	else {
		cout << "You don't have that." << endl;
	}
}

void Player::SetWeapon(Item* i_weapon)
{
	Creature::SetWeapon(i_weapon);
	if (m_weapon == i_weapon) { //succesfully equiped
		cout << "Equiped " << m_weapon->GetName() << "." << endl;
	}
	else {
		cout << "You don't have that item." << endl;
	}
}

void Player::Open(Item* i_item)
{
	if (m_location->Contains(i_item)) {
		i_item->Open();
	}
	else {
		cout << "That's not an item in this room." << endl;
	}
}

void Player::LookAround()
{
	m_location->Look();
}

void Player::Put(Item* i_item, Item* i_container)
{
	if (this->Contains(i_item) && m_location->Contains(i_container)) {
		i_container->AddEntity(this->RemoveEntity(i_item));
		if (i_container->Contains(i_item)) { //added successfully
			cout << "Item put." << endl;
		}
	}
	else {
		cout << "You don't have that." << endl;
	}
}

void Player::Attack(Creature* i_target, Item* i_weapon)
{
	if (i_weapon != NULL) {
		SetWeapon(i_weapon);
	}
	if (m_weapon != NULL) {
		SetCombatTarget(i_target);
		if (CanAttackTarget()) {
			cout << "You attack the " << m_combatTarget->GetName() << " with a " << m_weapon->GetName() << "." << endl;
			AttackTargetWithWeapon();
		}
		else {
			cout << "You can't attack that." << endl;
		}
		SetCombatTarget(NULL);
	}
	else {
		cout << "You don't have a weapon equiped." << endl;
	}
}

void Player::Unequip()
{
	if (m_weapon != NULL) {
		m_weapon = NULL;
		cout << "Unequiped." << endl;
	}
	else {
		cout << "You have nothing equiped." << endl;
	}
}

void Player::TakeDamage(int i_dmg)
{
	cout << "You take " << i_dmg << " damage." << endl;
	Creature::TakeDamage(i_dmg);
	if (!IsDead()) {
		cout << "You have " << m_curHP << " hit points remaining." << endl;
	}
}

void Player::Die()
{
	cout << "You are dead." << endl;
}
