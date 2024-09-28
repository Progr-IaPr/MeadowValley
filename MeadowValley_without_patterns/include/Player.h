#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Player {
private:
    sf::Vector2f position;
    bool isMoving;
    sf::Vector2f direction;
public:
    Player();

    // Movement methods with collision detection and screen bounds
    bool canMoveTo(const sf::Vector2f& newPosition, const sf::FloatRect& screenBounds);
    void moveUp(const sf::FloatRect& screenBounds);
    void moveDown(const sf::FloatRect& screenBounds);
    void moveLeft(const sf::FloatRect& screenBounds);
    void moveRight(const sf::FloatRect& screenBounds);

    sf::Vector2f getPosition() const;
    sf::Vector2f getDirection() const;
    bool getIsMoving() const;

    // Input handling
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed, const sf::FloatRect& screenBounds);
};

#endif // PLAYER_H