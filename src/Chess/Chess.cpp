#include "Chess/Chess.hpp"

Chess::Chess() {
    this->board = new Board();
}


Team Chess::getTurn() const {
    return this->turn;
}

void Chess::changeTurn() {
    this->turn = this->getTurn() == Team::WHITE ? Team::BLACK : Team::WHITE;
}

void Chess::printBoard() const {
    this->board->print();
}

