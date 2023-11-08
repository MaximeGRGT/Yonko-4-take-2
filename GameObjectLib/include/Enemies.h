#pragma once
#include <GameObject.h>
#include <Ressources.h>
#include <iostream>

class Enemy : public GameObject
{
private:
	int eHealth;
	int eWood;
	int eSize;
	int eSpeed;

public:
	Enemy(int health, int wood, int size, int speed)
		: eHealth(health), eWood(wood), eSize(size), eSpeed(speed) {}

	~Enemy() {};

	void dropWood(Ressources& ressources);
	void setWood(int wood) { eWood = wood; };
	void takeDamage(int damage) { 
		eHealth -= damage;  
		if (eHealth <= 0) {
			std::cout << "enemy dead";
			this->~Enemy();
		}
	};

	int getHealth() { return eHealth; };
	void setHealth(int health) { eHealth = health; };

	int getSize() { return eSize; };
	void setSize(int size) { eSize = size; };

	int getSpeed() { return eSpeed; };
	void setSpeed(int speed) { eSpeed = speed; };
};

class Boss : public Enemy
{
public:
	Boss() : Enemy(100, 50, 20, 5) {}
};

class Canard : public Enemy
{
public:
	Canard() : Enemy(20, 10, 5, 10) {}
};

class Zombie : public Enemy
{
public:
	Zombie() : Enemy(50, 5, 15, 2) {}
};