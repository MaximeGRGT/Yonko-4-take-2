#include "MoveMouse.h"
#include <iostream>
#include "GameObject.h"

GameObject game;

void SetMouse::MousePos(sf::Event& event) {
	switch (event.type) {
	case sf::Event::MouseButtonPressed:
		//std::cout << "Boutton presse" << std::endl;


		switch (event.key.code) {
		case sf::Mouse::Right:
			std::cout << "Boutton droit presse" << std::endl;

			break;

		case sf::Mouse::Left:
			std::cout << "Boutton gauche presse" << std::endl;

			break;
		}

		break;

	case sf::Event::MouseButtonReleased:
		//std::cout << "Boutton relache" << std::endl;

		switch (event.key.code) {
		case sf::Mouse::Right:
			std::cout << "Boutton droit relache" << std::endl;

			break;

		case sf::Mouse::Left:
			std::cout << "Boutton gauche relache" << std::endl;
		}

		break;

	case sf::Event::MouseMoved:
		std::cout << "x: " << event.mouseButton.x << std::endl;
		std::cout << "y: " << event.mouseButton.y << std::endl;
		

		break;
	}
}