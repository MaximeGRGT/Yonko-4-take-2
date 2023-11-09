#pragma once
#include "SFML/Graphics.hpp"
#include "Window.hpp"
#include "GameObject.h"

class Path : public GameObject {
public:
    Path(float x, float y);
    void draw(Window_s& window);
    sf::FloatRect getBounds() const {
        return _sprite.getGlobalBounds();
    }
    static constexpr float SIZE = 2.5f;
    static const int WIDTH = 100;
    static const int HEIGHT = 100;
private:

    sf::Sprite _sprite;
    sf::Texture _texture;


};