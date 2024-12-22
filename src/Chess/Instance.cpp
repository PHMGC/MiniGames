#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <chrono>
//#include "Chess/Game.hpp"
#include "../../include/Chess/Game.hpp"
#include "../../include/Chess/Instance.hpp"

using namespace std;

const int WIDTH = 1000;
const int HEIGHT = 800;
const int FPS = 144;

class Instance {
public:
    sf::Clock clock;
    sf::RenderWindow window;
    Game game;
    //MinMax minmax;
    sf::Vector2i last_pos_click;

    Instance() : window(sf::VideoMode(WIDTH, HEIGHT), "Game Window"), game(Board(sf::Vector2f((WIDTH - min(WIDTH, HEIGHT)) / 2, (HEIGHT - min(WIDTH, HEIGHT)) / 2), min(WIDTH, HEIGHT))), minmax(game) {
        start();
    }

    void handle_move_by_mouse() {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            pos = (pos - game.board.pos) / game.board.piece_size;
            cout << pos.x << ", " << pos.y << endl;

            if (last_pos_click != sf::Vector2i(-1, -1) && last_pos_click != pos) {
                if (game.make_move(last_pos_click, pos)) {
                    minmax.make_perfect_move();
                }
                last_pos_click = sf::Vector2i(-1, -1);
            } else if (game.piece_by_pos(pos)) {
                last_pos_click = pos;
            }
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    void start() {
        // game.debug_board_moves();
    }

    void update() {
        game.board.draw(window);
        handle_move_by_mouse();
    }

    void run() {
        while (window.isOpen()) {
            sf::Time deltaTime = clock.restart();
            window.clear(sf::Color(105, 105, 105)); // dim gray
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            update();
            window.display();
        }
    }
};

int main() {
    Instance engine;
    engine.run();
    return 0;
}

