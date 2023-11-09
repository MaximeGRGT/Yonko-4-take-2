#include "GameLoop.hpp"
#include <iostream>
#include "GameObject.h"
#include "Scene.h"
#include "MoveMouse.h"
#include "PhysicsManager.h"

bool isMousePressed = false;

GameLoop::GameLoop() 
{
    importantGameObjects = scene.CreateAllGameObjects();
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
        /*sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                isMousePressed = true;
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                isMousePressed = false;
            }
        }
        if (isMousePressed) {
            sf::Vector2i mousePosition = mouse.GetPosition(_window);
            importantGameObjects.SetPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
        }*/
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
