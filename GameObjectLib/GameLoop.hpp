#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.hpp"
#include "Scene.h"
#include "PhysicsManager.h"
#include "MoveMouse.h"
#include "GameObject.h"

class GameLoop {
public: 
    GameLoop();
    ~GameLoop();
    void run();

    void processEvents(float deltaTime);
    void update(float deltaTime);
    void render();
private:
    Window_s _window;
    Scene scene;
    std::vector<GameObject*> importantGameObjects;
    PhysicsManager physicsManager;
    SetMouse mouse;
};
