#pragma once
#include "GameObject.hpp"
#include "Ressources.h"
#include "Window.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Enemy : public GameObject {
private:
    int eWood;
    float eSize;
    int eSpeed;
    int eDamage;

    sf::Vector2f currentTarget;
    std::vector<sf::Vector2f> pathPoints;
    size_t currentPathIndex;

    bool isActive;
    float startTimer;

    sf::Texture eTexture;
    sf::Sprite eSprite;

public:
    Enemy(const std::string& texturePath, int wood, float size, int speed, int damage);
    virtual ~Enemy();

    void initializeStartTimer(float minDelay, float maxDelay);
    void updateActivation(float deltaTime);
    void dropWood(Ressources& ressources);
    void setWood(int wood);
    void draw(Window_s& window);
    void setPath(const std::vector<sf::Vector2f>& path);
    void move(float deltaTime);
    sf::Vector2f getSize() const;
    void setSize(float size);
    void takeDamage(int damage);
    bool isAlive() const;
    void update(float deltaTime);
    const sf::Sprite& getSprite() const;
    bool getIsActive() const;
    int getSpeed();
    void setSpeed(int speed);
};

class Boss : public Enemy {
public:
    Boss(const std::string& texturePath);
};

class Enemy1 : public Enemy {
public:
    Enemy1(const std::string& texturePath);
};

class Enemy2 : public Enemy {
public:
    Enemy2(const std::string& texturePath);
};

class Enemy3 : public Enemy {
public:
    Enemy3(const std::string& texturePath);
};
