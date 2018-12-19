#include "engine.h"

Engine::Engine() 
{
	window.create(sf::VideoMode(1280, 720), "Gra");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	ui = std::make_unique<UI>(window);
	ui->init();
	items.push_back(new Items(0, "weap1.png"));
	
	player = std::make_unique<Player>(window);
}

Engine::~Engine()
{
}

void Engine::loop()
{
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			//zaklada bron z ekwipunku na lewa reke (tu p owinno byc JAKA BRON)
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
				player->equipWeapon(Slot::leftHand);
				items[0]->setPosition(ui->getSlot(0));
			}
			//lootuje item do torby
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L) {
				player->lootItem(items[0]);
			}
			//wyswietla zawartosc torby
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
				
			}
		}
		this->update();
		this->draw();
	}
}

void Engine::update()
{
	player->update();
}

void Engine::draw()
{
	window.clear();
	ui->draw();
	for (auto &u : items)
		u->draw(window);
	player->draw();
	window.display();
}
