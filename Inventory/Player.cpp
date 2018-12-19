#include "Player.h"

Player::Player(sf::RenderWindow &_window) :window(_window)
{
	isVisible = false;
	bag = std::make_unique<Inventory>();
	bag->init();
	leftHand = nullptr;
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
	if (isVisible)
		bag->drawBag(window);
}

void Player::lootItem(const std::string &_name)
{
	bag->addItem(_name);
	std::cout << "Looted: " << _name;
}

void Player::equipWeapon(Slot _slot)
{
	//equip bez wyszukiwania itemu!!! na razie  testowo 
	if (_slot == Slot::leftHand)
		//leftHand = inventory->getItem();
	if (_slot == Slot::rightHand)
		//rightHand = inventory->getItem();
	std::cout << "Zalozylem bron!" << "\n";
}

void Player::unequipeWeapon(Slot _slot)
{
	if (_slot == Slot::leftHand)
		leftHand = nullptr;
	if (_slot == Slot::rightHand)
		rightHand = nullptr;
}

void Player::showBag()
{
	if (isVisible)
		isVisible = false;
	else
		isVisible = true;
}


