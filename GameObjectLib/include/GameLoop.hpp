#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.hpp"
#include "Map.hpp"
#include "Enemies.h"
#include "Tower.hpp"
#include "GameObject.hpp"
class GameLoop {
public:
    GameLoop();
    ~GameLoop();
    void run();

    void processEvents(float deltaTime);
    void update(float deltaTime);
    void render();
    void initializeWaves();
    void initializeTurrets();

private:


    Window_s _window;
    Map _map;

    // Waves managment
    std::map<int, std::vector<std::unique_ptr<Enemy>>> waves;
    int currentWave;

    // Towers
    std::vector<std::unique_ptr<Tower>> towers;

    std::unique_ptr<Tower> inactiveTower1;
    std::unique_ptr<Tower> inactiveTower2;
    std::unique_ptr<Tower> inactiveTower3;
};
