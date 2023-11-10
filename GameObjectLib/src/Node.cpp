#include "Node.hpp"

Node::Node(sf::Vector2i pos, Node* p) : position(pos), gCost(0), hCost(0), parent(p) {}

Node::~Node()
{

}

int Node::fCost() const {
    return gCost + hCost;
}

int Node::heuristic(const sf::Vector2i& a, const sf::Vector2i& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

std::vector<sf::Vector2i> Node::getNeighbors() {
    return {
        {position.x + 1, position.y},
        {position.x - 1, position.y},
        {position.x, position.y + 1},
        {position.x, position.y - 1}
    };
}

std::vector<sf::Vector2i> Node::findPath(const std::vector<std::vector<bool>>& matrix, const sf::Vector2i& start, const sf::Vector2i& target) {
    auto cmp = [](Node* a, Node* b) { return a->fCost() > b->fCost(); };
    std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> openSet(cmp);
    std::unordered_set<int> closedSet; // To keep track of visited nodes

    Node* startNode = new Node(start);
    openSet.push(startNode);

    while (!openSet.empty()) {
        Node* currentNode = openSet.top();
        openSet.pop();

        // Reached target
        if (currentNode->position == target) {
            std::vector<sf::Vector2i> path;
            while (currentNode) {
                path.push_back(currentNode->position);
                currentNode = currentNode->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        int hash = currentNode->position.y * matrix.size() + currentNode->position.x;
        if (closedSet.find(hash) != closedSet.end()) {
            continue;
        }

        closedSet.insert(hash);

        for (const auto& neighborPos : currentNode->getNeighbors()) {
            // Check boundaries and if it's a wall
            if (neighborPos.x < 0 || neighborPos.y < 0 || neighborPos.x >= matrix[0].size() || neighborPos.y >= matrix.size() || matrix[neighborPos.y][neighborPos.x]) {
                continue;
            }

            Node* neighbor = new Node(neighborPos, currentNode);
            neighbor->gCost = currentNode->gCost + 1;
            neighbor->hCost = neighbor->heuristic(neighborPos, target);

            openSet.push(neighbor);
        }
    }

    // If no path is found, return an empty vector
    return {};
}
