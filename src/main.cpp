//SFML docs: https://www.sfml-dev.org/tutorials/3.0/
//           https://www.sfml-dev.org/documentation/3.0.0/topics.html

#include "Chess/Board.hpp"
#include <iostream>
#include <iomanip> // Para manipular espaçamento

#include <SFML/Graphics.hpp>

int main() {
    Board board{};

    std::cout << "    a   b   c   d   e   f   g   h" << std::endl;
    for (int y = 7; y >= 0; y--) { // Imprimir o tabuleiro de cima para baixo
        std::cout << " " << y + 1 << " "; // Rotular as linhas
        for (int x = 0; x < 8; x++) {
            if (Piece* piece = board.getPieceAt(Position(x, y))) {
                std::cout << (piece->getTeam() == WHITE ? " W" : " B") // Time
                          << piece->getName().substr(0, 1) // Primeira letra do nome
                          << " ";
            } else {
                std::cout << " -- "; // Espaçamento uniforme para células vazias
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
