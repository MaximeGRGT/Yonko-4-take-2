#pragma once

#include <SFML/Graphics.hpp>

struct MouseState {
    bool isLeftButtonPressed;
    bool isRightButtonPressed;
    int mouseX;
    int mouseY;
};

class SetMouse
{

public:
	void MousePos(sf::Event& event);

};