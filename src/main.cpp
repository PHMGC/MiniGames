#include <SFML/Graphics.hpp>

int main() {
    //Código teste do SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Screen update
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
