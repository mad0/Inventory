#include "engine.h"

Engine::Engine() 
{
	window.create(sf::VideoMode(1280, 720), "Gra");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	ui = std::make_unique<UI>(window);
	ui->init();
	s_bag = false;
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
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
				if (s_bag)
					s_bag = false;
				else
					s_bag = true;
			}
		}
		this->update();
		this->draw();
	}
}

void Engine::update()
{
}

void Engine::draw()
{
	window.clear();
	if (s_bag)
		ui->drawBag();
	ui->drawUI();
	window.display();
}
