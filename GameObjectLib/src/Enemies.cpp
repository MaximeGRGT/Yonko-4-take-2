#include "Enemy.hpp"
#include <iostream>
#include <random>
#include <cmath>

Enemy::Enemy(const std::string& texturePath, int wood, float size, int speed, int damage) 
    : eWood(wood), eSize(size), eSpeed(speed), eDamage(damage), currentPathIndex(0), isActive(false), startTimer(0.0f) {
    if (!eTexture.loadFromFile(texturePath)) {
        std::cerr << "Could not load texture from: " << texturePath << std::endl;
    }
    eSprite.setTexture(eTexture);
    eSprite.setScale(eSprite.getScale().x * size, eSprite.getScale().y * size);
    sf::FloatRect bounds = eSprite.getLocalBounds();
    eSprite.setOrigin(bounds.width / 2, bounds.height / 2);
    eSprite.setPosition(-30, ((1080 / 20) * 2) / 2.0f);
}

Enemy::~Enemy() {}

void Enemy::initializeStartTimer(float minDelay, float maxDelay) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(minDelay, maxDelay);
    startTimer = distr(gen);
}

void Enemy::updateActivation(float deltaTime) {
    if (!isActive) {
        if (startTimer <= 0) {
            isActive = true;
        } else {
            startTimer -= deltaTime;
        }
    }
}

void Enemy::dropWood(Ressources& ressources) {
    // Implement this function
}

void Enemy::setWood(int wood) {
    eWood = wood;
}

void Enemy::draw(Window_s& window) {
    window.addToRenderLayer(ENEMY, eSprite);
}

void Enemy::setPath(const std::vector<sf::Vector2f>& path) {
    pathPoints = path;
    currentPathIndex = 0;
    if (!pathPoints.empty()) {
        currentTarget = pathPoints[0];
    }
}

void Enemy::move(float deltaTime) {
    if (!isActive || pathPoints.empty()) return;

    sf::Vector2f direction = currentTarget - eSprite.getPosition();
    float distanceToTarget = std::hypot(direction.x, direction.y);

    if (distanceToTarget < eSpeed * deltaTime) {
        eSprite.setPosition(currentTarget);
        currentPathIndex++;
        if (currentPathIndex < pathPoints.size()) {
            currentTarget = pathPoints[currentPathIndex];
        } else {
            pathPoints.clear(); // Enemy has finished the path
        }
    } else {
        sf::Vector2f movement = eSpeed * deltaTime * direction / distanceToTarget;
        eSprite.move(movement);
    }
}

sf::Vector2f Enemy::getSize() const {
    auto &scale = eSprite.getScale();
    auto textureSize = eTexture.getSize();
    return sf::Vector2f(textureSize.x * scale.x, textureSize.y * scale.y);
}

void Enemy::setSize(float size) {
    eSprite.setScale(size / eTexture.getSize().x, size / eTexture.getSize().y);
}

void Enemy::takeDamage(int damage) {
    float newSizeX = getSize().x - damage;
    float newSizeY = getSize().y - damage;
    eSprite.setScale(newSizeX / eTexture.getSize().x, newSizeY / eTexture.getSize().y);

    if (newSizeX < 10 || newSizeY < 10) {
        isActive = false;
    }
}

bool Enemy::isAlive() const {
    return (getSize().x >= 10.f && getSize().y >= 10.f);
}

void Enemy::update(float deltaTime) {
    updateActivation(deltaTime);
    if (!isAlive()) {
        return;
    }
    move(deltaTime);
}

const sf::Sprite& Enemy::getSprite() const {
    return eSprite;
}

bool Enemy::getIsActive() const {
    return isActive;
}

int Enemy::getSpeed() {
    return eSpeed;
}

void Enemy::setSpeed(int speed) {
    eSpeed = speed;
}

Boss::Boss(const std::string& texturePath) : Enemy(texturePath, 1000, 1, 100, 10) {}

Enemy1::Enemy1(const std::string& texturePath) : Enemy(texturePath, 20, 1, 100, 2) {}

Enemy2::Enemy2(const std::string& texturePath) : Enemy(texturePath, 50, 1, 200, 5) {}

Enemy3::Enemy3(const std::string& texturePath) : Enemy(texturePath, 70, 1, 300, 10) {}
