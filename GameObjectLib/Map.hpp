#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Window.hpp"
#include "sstream"
#include "fstream"



class Map {
public:

    Map(const std::string& mapFilePath) : _mapFilePath(mapFilePath) {}
    void LoadMap(Window_s& window) {
        std::ifstream file(_mapFilePath);
        std::string line;
        while (std::getline(file, line)) {
            std::vector<bool> row;
            std::istringstream iss(line);
            char ch;
            while (iss >> ch) {
                if (ch == '0')
                    row.push_back(false);
                else {
                    if (ch == '1')
                        row.push_back(true);
                }
            }
            _mapGrid.push_back(row);
        }

        size_t maxRow = 0;
        for (const auto& row : _mapGrid) {
            if (row.size() > maxRow) {
                maxRow = row.size();
            }
        }
        _walls.reserve(_mapGrid.size() * maxRow);
        _paths.reserve(_mapGrid.size() * maxRow);

        for (size_t i = 0; i < _mapGrid.size(); i++) {
            for (size_t j = 0; j < _mapGrid[i].size(); j++) {
                if (_mapGrid[i][j]) {
                    ;
                }
                else {
                    _paths.emplace_back(j * Path::WIDTH, i * Path::HEIGHT);
                    _paths.back().draw(window);
                }
            }
        }

    }

private:
    std::vector<std::vector<bool>> _mapGrid;
    std::string _mapFilePath;
    std::vector<Wall> _walls;
    std::vector<Path> _paths;

};