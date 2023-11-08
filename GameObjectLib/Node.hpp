// Node.hpp
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_set>

class Node {
public:
    sf::Vector2i position;
    int gCost; // Cost from start to current node
    int hCost; // Heuristic cost from current node to target
    Node* parent;

    Node(sf::Vector2i pos, Node* p = nullptr);
    ~Node();
    int fCost() const;
    int heuristic(const sf::Vector2i& a, const sf::Vector2i& b);
    std::vector<sf::Vector2i> getNeighbors();
    std::vector<sf::Vector2i> findPath(const std::vector<std::vector<bool>>& matrix, const sf::Vector2i& start, const sf::Vector2i& target);
};
