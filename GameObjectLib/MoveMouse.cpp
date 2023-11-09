#include "MoveMouse.h"
#include <iostream>
#include "GameObject.h"
#include "Scene.h"

MouseState mouseState;

void SetMouse::MousePos(sf::Event& event) {
	switch (event.type) {
	case sf::Event::MouseButtonPressed:
		//std::cout << "Boutton presse" << std::endl;


		switch (event.key.code) {
		case sf::Mouse::Right:
			std::cout << "Bouton droit presse" << std::endl;
			mouseState.isRightButtonPressed = true;

			break;

		case sf::Mouse::Left:
			std::cout << "Bouton gauche presse" << std::endl;
			mouseState.isLeftButtonPressed = true;

			break;
		}

		break;

	case sf::Event::MouseButtonReleased:
		//std::cout << "Boutton relache" << std::endl;

		switch (event.key.code) {
		case sf::Mouse::Right:
			std::cout << "Bouton droit relache" << std::endl;
			mouseState.isRightButtonPressed = false;

			break;

		case sf::Mouse::Left:
			std::cout << "Bouton gauche relache" << std::endl;
			mouseState.isLeftButtonPressed = false;
		}

		break;

	case sf::Event::MouseMoved:
		mouseState.mouseX = event.mouseMove.x;
		mouseState.mouseY = event.mouseMove.y;

		break;
	}
}