#include "GameLoop.hpp"
#include <iostream>


GameLoop::GameLoop() : _map("asset/MAP.txt"), currentWave(1)
{

    // Charge map
    _map.LoadMap(_window);
    // Load map into layer
    _map.draw(_window);


    // Load Turrets
    initializeTurrets();


    // Load enemies
    initializeWaves();


    // Load enemies into layer
    for (auto& enemy : waves[currentWave]) {
        enemy->draw(_window);
    }

    // Load Turrets into layer
    for (auto& turret : towers) {
        turret->draw(_window);
    }
}

GameLoop::~GameLoop() 
{

}

void GameLoop::initializeTurrets() {
    sf::Vector2f pos(10, 1000);


    inactiveTower1 = std::make_unique<Tower1>(pos, "asset/tour1.png");

    pos.x += 80;
    inactiveTower2 = std::make_unique<Tower2>(pos, "asset/tour2.png");

    pos.x += 80;
    inactiveTower3 = std::make_unique<Tower3>(pos, "asset/tour3.png");
}


void GameLoop::initializeWaves() {
    // Wave 1
    for (int i = 0; i < 10; ++i) {
        waves[1].push_back(std::make_unique<Enemy1>("asset/Enemy1.png"));
    }
    // Wave 2
    for (int i = 0; i < 5; ++i) {
        waves[2].push_back(std::make_unique<Enemy1>("asset/Enemy1.png"));
    }
    for (int i = 0; i < 5; ++i) {
        waves[2].push_back(std::make_unique<Enemy2>("asset/Enemy2.png"));
    }
    // Wave 3
    for (int i = 0; i < 5; ++i) {
        waves[3].push_back(std::make_unique<Enemy2>("asset/Enemy2.png"));
    }
    for (int i = 0; i < 3; ++i) {
        waves[3].push_back(std::make_unique<Enemy3>("asset/Enemy3.png"));
    }
    // Wave 4
    for (int i = 0; i < 10; ++i) {
        waves[4].push_back(std::make_unique<Enemy3>("asset/Enemy3.png"));
    }
    // Wave 5
    waves[5].push_back(std::make_unique<Boss>("asset/Boss.png"));

    std::vector<sf::Vector2f> pathPoints = _map.getPathPoints(_window);
    for (auto& wavePair : waves) {
        for (auto& enemy : wavePair.second) {
            enemy->setPath(pathPoints);
            enemy->initializeStartTimer(0.0f, 10.0f);

        }
    }
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

void GameLoop::processEvents(float deltaTime) {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            _window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(_window.getWindow());
            sf::Vector2f worldPos = _window.getWindow().mapPixelToCoords(mousePos);

            switch (event.key.code) {
            case sf::Keyboard::A:
                // Créer et activer une nouvelle tourelle de type 1
                towers.push_back(std::make_unique<Tower1>(worldPos, "asset/tour1.png"));
                break;
            case sf::Keyboard::Z:
                // Créer et activer une nouvelle tourelle de type 2
                towers.push_back(std::make_unique<Tower2>(worldPos, "asset/tour2.png"));
                break;
            case sf::Keyboard::E:
                // Créer et activer une nouvelle tourelle de type 3
                towers.push_back(std::make_unique<Tower3>(worldPos, "asset/tour3.png"));
                break;
            }
        }
    }
}





void GameLoop::update(float deltaTime)
{
    std::cout << waves[currentWave].size() << std::endl;
    if (waves[currentWave].empty() && waves.count(currentWave + 1)) {
        currentWave++;
        //std::cout << "Prok\n";

        for (auto& enemy : waves[currentWave]) {
            enemy->initializeStartTimer(0.0f, 10.0f);
            enemy->draw(_window);
        }
    }

    auto& enemies = waves[currentWave];
    for (auto it = enemies.begin(); it != enemies.end();) {
        auto& enemy = *it;
        enemy->updateActivation(deltaTime);

        if (enemy->isAlive() && enemy->getIsActive()) {
            enemy->move(deltaTime);
            //std::cout << "Alive\n";
            ++it;
        }
        else if (!enemy->isAlive()) {
            _window.removeFromRenderLayer(3, enemy->getSprite());
            it = enemies.erase(it);
            //std::cout << "Dead\n";
        }
        else {
            ++it;   
        }
    }


    // Towers managment
    for (auto& tower : towers) {
        //std::cout << "test";
        tower->update(deltaTime, waves[currentWave], _window);
        
    }
}

void GameLoop::render() {
    _window.clear();
    for (auto& tower : towers) {
        if (tower) {
            tower->draw(_window);
        }
    }

    _window.renderLayers();
    _window.display();
}