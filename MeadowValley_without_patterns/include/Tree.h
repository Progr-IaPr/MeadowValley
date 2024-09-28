#ifndef TREE_H
#define TREE_H

#include <SFML/Graphics.hpp>

class Tree {
private:
    sf::Vector2f position;
public:
    Tree(const sf::Vector2f& position) : position(position) {}

    sf::Vector2f getPosition() const { return position; }
};

#endif