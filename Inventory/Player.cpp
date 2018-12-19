#include "Player.h"


Player::Player(sf::RenderWindow &_window) :window(_window)
{
	inventory = new Inventory();
	inventory->init();
	//leftHand = nullptr;
	rightHand = nullptr;
	
}


Player::~Player()
{

}

void Player::update()
{
	
}

void Player::draw()
{
	inventory->drawBag(window);
}

void Player::lootItem(Items * _item)
{
	inventory->addItem(_item);
	std::cout << "Looted: " << _item;
}

void Player::equipWeapon(Slot _slot)
{
	//equip bez wyszukiwania itemu!!! na razie  testowo 
	if (_slot == Slot::leftHand)
		leftHand = inventory->getItem();
	if (_slot == Slot::rightHand)
		rightHand = inventory->getItem();
	std::cout << "Zalozylem bron!" << "\n";
}

void Player::unequipeWeapon(Slot _slot)
{
	if (_slot == Slot::leftHand)
		leftHand = nullptr;
	if (_slot == Slot::rightHand)
		rightHand = nullptr;
}


