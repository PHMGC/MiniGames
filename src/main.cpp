//SFML docs: https://www.sfml-dev.org/tutorials/3.0/
//           https://www.sfml-dev.org/documentation/3.0.0/topics.html

#include "Chess/Board.hpp"
#include <iostream>
#include <iomanip> // Para manipular espaçamento

#include <SFML/Graphics.hpp>

int main() {
    Board board{};

    board.print();

    return 0;
}
