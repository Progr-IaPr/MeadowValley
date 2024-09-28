#include <SFML/Graphics.hpp>
#include "./include/World.h"
#include "WorldUI.h"
#include "./include/Player.h"

int main() {
    // Setup window, framerate
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Meadow Valley", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    // Create World and WorldUI instances
    World world;
    WorldUI worldUI;

    // Create player instance
    Player player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle exit with Escape key
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

            // Handle player input
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {

                sf::Vector2u windowSize = window.getSize();

                // Define screen bounds as the boundary of the window
                sf::FloatRect screenBounds(0, 0, windowSize.x, windowSize.y);

                // Pass obstacles and screen bounds to handlePlayerInput
                player.handlePlayerInput(event.key.code, event.type == sf::Event::KeyPressed, screenBounds);
            }
        }

        // Clear window
        window.clear();

        // Update and render world and player
        worldUI.render(window, world, player);

        // Display the window
        window.display();
    }

    return 0;
}