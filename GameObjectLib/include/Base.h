#pragma once
#include <GameObject.h>

class Base : public GameObject
{
private:
	int baseHealth;

public:
	void takeDamage(int damage) { baseHealth -= damage; };

	int getHealth() { return baseHealth; };
	void setHealth(int health) { baseHealth = health; };
};