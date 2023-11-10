#include "Map.hpp"
#include <sstream>
#include <fstream>

Map::Map(const std::string& mapFilePath) : _mapFilePath(mapFilePath) {}

void Map::draw(Window_s& window) {
    window.addToRenderLayer(BACKGROUND, backGroundSprite);
    window.addToRenderLayer(BASE, baseSprite);
    for (auto& sprite : pathSprites) {
        window.addToRenderLayer(PATH, sprite);
    }
}

void Map::LoadMap(Window_s& window) {
    // Load background plan
    baseTex.setSmooth(true);
    backGroundTex.setSmooth(true);

    if (!baseTex.loadFromFile("asset/BaseTowerDefense.png") ||
        !backGroundTex.loadFromFile("asset/BackGroundTowerdefense.png") ||
        !pathTex.loadFromFile("asset/Path.png")) {
        std::cerr << "Error while loading texture" << std::endl;
        return;
    }

    baseSprite.setTexture(baseTex);
    backGroundSprite.setTexture(backGroundTex);
    baseSprite.setPosition(1920 - 80, 1080 - 250);

    // Load matrice path
    float scaleX = 1920.0f / (20 * pathTex.getSize().x);
    float scaleY = 1080.0f / (20 * pathTex.getSize().y);

    std::ifstream file(_mapFilePath);
    std::string line;
    int y = 0;
    while (std::getline(file, line)) {
        std::vector<bool> row;
        std::istringstream iss(line);
        char ch;
        int x = 0;
        while (iss >> ch) {
            if (ch == '0') {
                row.push_back(false);
                sf::Sprite pathSprite(pathTex);
                pathSprite.setScale(scaleX, scaleY);
                pathSprite.setPosition(x * (1920.0f / 20), y * (1080.0f / 20));
                pathSprites.push_back(pathSprite);
            }
            else if (ch == '1') {
                row.push_back(true);
            }
            x++;
        }
        y++;
        _mapGrid.push_back(row);
    }
}

const std::vector<std::vector<bool>>& Map::getMapGrid() const {
    return _mapGrid;
}

std::vector<sf::Vector2f> Map::getPathPoints(Window_s &window) const {
    std::vector<sf::Vector2f> points;
    
    float tileWidth = static_cast<float>(window.getWindow().getSize().x) / 20;
    float tileHeight = static_cast<float>(window.getWindow().getSize().y) / 20;
    for (int y = 0; y < _mapGrid.size(); ++y) {
        for (int x = 0; x < _mapGrid[y].size(); ++x) {
            if (!_mapGrid[y][x]) { // Si la cellule est un "0"
                points.emplace_back(x * tileWidth + tileWidth / 2.0f, y * tileHeight + tileHeight / 2.0f);
            }
        }
    }
    return points;
}

