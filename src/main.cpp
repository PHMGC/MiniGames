#include <SFML/Graphics.hpp>

using namespace std;

 
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }
 
        // Clear screen
        window.clear();
 
        // Draw the string
        //window.draw(text);
 
        // Update the window
        window.display();
    }
}
