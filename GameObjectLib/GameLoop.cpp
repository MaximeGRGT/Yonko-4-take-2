#include "GameLoop.hpp"
#include <iostream>


GameLoop::GameLoop() 
{

}

GameLoop::~GameLoop() 
{

}


void GameLoop::run() {
    sf::Clock clock;

    while (_window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        processEvents(deltaTime);
        update(deltaTime);
        render();
    }
}

void GameLoop::processEvents(float deltaTime)
{
    sf::Event event;

    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
        }


    }
}


void GameLoop::update(float deltaTime)
{

}

void GameLoop::render() {
    _window.clear();
    _window.renderLayers();
    _window.display();
}
