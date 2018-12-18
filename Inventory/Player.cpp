#include "Player.h"

Player::Player(sf::RenderWindow &_window) :window(_window)
{
	ui = std::make_unique<UI>(window);
	ui->init();
	playerBag = std::make_unique<Inventory>();
	playerBag->addItem();
}


Player::~Player()
{
}

void Player::update()
{
}

void Player::draw()
{
	ui->ui_draw();
}

void Player::showBag()
{
	ui->showInv();
}
