#pragma once
#include <GameObject.h>
#include <Ressources.h>
#include <Base.h>
#include <iostream>

class Enemy : public GameObject
{
private:
	int eHealth;
	int eWood;
	int eSize;
	int eSpeed;
	int eDamage;

public:
	Enemy(int health, int wood, int size, int speed, int damage)
		: eHealth(health), eWood(wood), eSize(size), eSpeed(speed), eDamage(damage) {}

	~Enemy() {};

	void dropWood(Ressources& ressources);
	void setWood(int wood) { eWood = wood; };
	void takeDamage(int damage) { 
		eHealth -= damage;  
	};
	void move();
	void attackBase(Base& target);

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
	Boss() : Enemy(100, 50, 20, 5, 10) {}
};

class Canard : public Enemy
{
public:
	Canard() : Enemy(20, 10, 5, 10, 2) {}
};

class Zombie : public Enemy
{
public:
	Zombie() : Enemy(50, 5, 15, 2, 5) {}
};