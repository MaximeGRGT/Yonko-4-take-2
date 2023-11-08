#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.hpp"

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


};
