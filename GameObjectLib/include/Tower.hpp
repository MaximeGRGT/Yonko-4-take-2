#pragma once
#include <SFML/Graphics.hpp>
#include "Enemies.h"
#include <vector>
#include <memory>
#include <math.h>
#include "GameObject.hpp"

class Tower : GameObject {
private:
    sf::Sprite _sprite;
    std::shared_ptr<sf::Texture> texture;
    float attackRange;
    float attackSpeed;
    float timeSinceLastAttack;
    std::vector<std::weak_ptr<Enemy>> enemiesInRange;
    sf::RectangleShape line;
public:
    Tower(const sf::Vector2f& position, const std::string& texturePath, float range, float speed)
        : attackRange(range), attackSpeed(speed), timeSinceLastAttack(0.0f) {
        texture = std::make_shared<sf::Texture>(); // Allocate new texture
        if (!texture->loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture");
        }
        _sprite.setTexture(*texture); // Set the texture to the sprite
        _sprite.setPosition(position);
        sf::FloatRect bounds = _sprite.getLocalBounds();

        _sprite.setOrigin(bounds.width / 2, bounds.height / 2);

    }

    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    void update(float deltaTime, const std::vector<std::unique_ptr<Enemy>>& enemies, Window_s &window) {
        timeSinceLastAttack += deltaTime;

        if (timeSinceLastAttack >= 1.0f / attackSpeed) {
            for (const auto& enemyPtr : enemies) {

                if (enemyPtr && distanceTo(enemyPtr->getSprite().getPosition()) <= attackRange) {
                    enemyPtr->takeDamage(1); // degat

                    

                    line.setSize(sf::Vector2f(3.0f, distanceTo(enemyPtr->getSprite().getPosition())));
                    line.setOrigin(1.5f, 0);
                    line.setPosition(_sprite.getPosition());
                    line.setRotation(std::atan2(enemyPtr->getSprite().getPosition().y - _sprite.getPosition().y, enemyPtr->getSprite().getPosition().x - _sprite.getPosition().x) * 180 / 3.1316f);
                    //line.setFillColor(sf::Color::Red);
                    window.addToRenderLayer(6, line);
                    
                }
            }
            timeSinceLastAttack = 0.0f;
        }
    }




    void attack(const std::vector<std::shared_ptr<Enemy>>& enemies) {
        for (const auto& enemy : enemies) {
            if (auto &e = enemy) {
                float distance = distanceTo(e->getSprite().getPosition());
                if (distance <= attackRange) {
                    e->takeDamage(1);
                }
            }
        }
    }

    void draw(Window_s &window) {
        window.addToRenderLayer(TOWER, _sprite);
    }

    float distanceTo(const sf::Vector2f& enemyPos) {
        sf::Vector2f delta = enemyPos - _sprite.getPosition();
        return std::sqrt(delta.x * delta.x + delta.y * delta.y);
    }
    void setPosition(sf::Vector2f pos) {
        _sprite.setPosition(pos);
    }

    const sf::Vector2f getPosition() {
        return _sprite.getPosition();
    }
};



class Tower1 : public Tower {
public:
    Tower1(const sf::Vector2f& position, const std::string& texturePath) : Tower(position, texturePath, 100.0f, 1.0f) {}
};

class Tower2 : public Tower {
public:
    Tower2(const sf::Vector2f& position, const std::string& texturePath) : Tower(position, texturePath, 200.0f, 2.0f) {}
};

class Tower3 : public Tower {
public:
    Tower3(const sf::Vector2f& position, const std::string& texturePath) : Tower(position, texturePath, 300.0f, 3.0f) {}
};