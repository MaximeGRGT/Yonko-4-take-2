#include "PhysicsManager.h"
#include "MoveMouse.h"
#include "GameObject.h"
#include "Maths/Vector2.h"

void PhysicsManager::MoveGameObjectWithMouse(GameObject& gameObject, MouseState& mouseState) {
    // V�rifier si le bouton gauche de la souris est press�
    if (mouseState.isLeftButtonPressed) {
        // D�placer le GameObject en fonction de la position de la souris
        const Maths::Vector2f mousePosition(mouseState.mouseX, mouseState.mouseY);
        gameObject.SetPosition(mousePosition);
    }
}
