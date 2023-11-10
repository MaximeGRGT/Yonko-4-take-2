#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Window.hpp"
#include <iostream>
#include "GameObject.hpp"

class Map : GameObject {
public:
    Map(const std::string& mapFilePath);
    void draw(Window_s& window);
    void LoadMap(Window_s& window);
    
    std::vector<sf::Vector2f> getPathPoints(Window_s& window) const;
    const std::vector<std::vector<bool>>& getMapGrid() const;

private:
    sf::Texture baseTex, backGroundTex, pathTex;
    sf::Sprite baseSprite, backGroundSprite, pathSprite;
    std::vector<std::vector<bool>> _mapGrid;
    std::string _mapFilePath;
    std::vector<sf::Sprite> pathSprites;
};
