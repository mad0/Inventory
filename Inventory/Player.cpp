#include "Player.h"


Player::Player(sf::RenderWindow &_window) :window(_window)
{

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
	
}

void Player::lootItem(const std::string & _name)
{
	bag.push_back(new Items(1, _name));
	std::cout << "Looted: " << _name<<"\n";
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


