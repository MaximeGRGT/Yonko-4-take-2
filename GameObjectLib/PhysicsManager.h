#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "MoveMouse.h"
#include "Maths/Vector2.h"


class PhysicsManager {

public:
	void MoveGameObjectWithMouse(GameObject& gameObject, MouseState& mouseState);
};
