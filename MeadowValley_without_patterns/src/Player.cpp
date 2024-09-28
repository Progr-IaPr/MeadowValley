#include "../include/Player.h"
#include <iostream>
#include "SFML/Graphics.hpp"

Player::Player() : isMoving(false), direction(0, 0), position(370.f, 900.f) {}

// Collision detection function with screen bounds
bool Player::canMoveTo(const sf::Vector2f& newPosition, const sf::FloatRect& screenBounds) {
    const float playerWidth = 64.0f;
    const float playerHeight = 64.0f;  

    // Define bounds for the player's movement area
    sf::FloatRect playerBounds(newPosition.x, newPosition.y, playerWidth, playerHeight);

    // Define the lower river boundary as the upper limit for player movement
    float lowerRiverBoundary = screenBounds.height * 0.45f + 50;

    // Prevent player from moving above the river boundary
    if (playerBounds.top < lowerRiverBoundary) {
        return false;
    }

    // Adjust the bottom boundary to raise it a bit
    float adjustedBottomBoundary = screenBounds.height - 10;

    // Prevent player from moving outside the screen bounds
    if (playerBounds.left < screenBounds.left || 
        playerBounds.left + playerBounds.width > screenBounds.width || 
        playerBounds.top + playerBounds.height > adjustedBottomBoundary) {
        return false;
    }

    return true;
}

// Movement functions with collision and screen bounds checking
void Player::moveUp(const sf::FloatRect& screenBounds) {
    const float stepSize = 2.0f; 
    sf::Vector2f newPosition = position;
    newPosition.y -= stepSize; 
    if (canMoveTo(newPosition, screenBounds)) {
        position = newPosition;
        direction = sf::Vector2f(0, -1);
        isMoving = true;
    }
}

void Player::moveDown(const sf::FloatRect& screenBounds) {
    const float stepSize = 2.0f;
    sf::Vector2f newPosition = position;
    newPosition.y += stepSize; 
    if (canMoveTo(newPosition, screenBounds)) {
        position = newPosition;
        direction = sf::Vector2f(0, 1);
        isMoving = true;
    }
}

void Player::moveLeft(const sf::FloatRect& screenBounds) {
    const float stepSize = 2.0f;
    sf::Vector2f newPosition = position;
    newPosition.x -= stepSize;
    if (canMoveTo(newPosition, screenBounds)) {
        position = newPosition;
        direction = sf::Vector2f(-1, 0);
        isMoving = true;
    }
}

void Player::moveRight(const sf::FloatRect& screenBounds) {
    const float stepSize = 2.0f;
    sf::Vector2f newPosition = position;
    newPosition.x += stepSize;
    if (canMoveTo(newPosition, screenBounds)) {
        position = newPosition;
        direction = sf::Vector2f(1, 0);
        isMoving = true;
    }
}

// Getter functions 
sf::Vector2f Player::getPosition() const {
    return position;
}

sf::Vector2f Player::getDirection() const {
    return direction;
}

bool Player::getIsMoving() const {
    return isMoving;
}

// Input handling
void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed, const sf::FloatRect& screenBounds) {
    if (isPressed) {
        switch (key) {
        case sf::Keyboard::W: moveUp(screenBounds); break;
        case sf::Keyboard::S: moveDown(screenBounds); break;
        case sf::Keyboard::A: moveLeft(screenBounds); break;
        case sf::Keyboard::D: moveRight(screenBounds); break;
        default: break;
        }
    }
    else {
        isMoving = false;
    }
}