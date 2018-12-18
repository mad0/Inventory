#include "Player.h"

Player::Player(sf::RenderWindow &_window) :window(_window)
{
	playerBag = std::make_unique<Inventory>(window);
	playerBag->init();
	playerBag->addItem();
	isVisible = false;
}


Player::~Player()
{
}

void Player::update()
{
}

void Player::draw()
{
	//if (!isVisible)
		playerBag->drawSlots();
}

void Player::showBag()
{
	if (isVisible)
		isVisible = false;
	else isVisible = true;
}

