#include <stdexcept>

#include "Chess/Pieces/Knight.hpp"

bool Knight::isDefaultMove(Position move) {
    // Movimento padrão do cavalo
    return move.isEqual(2, 1) || move.isEqual(1, 2);
}

// Checar se o movimento é valido
bool Knight::canMove(const Position move) {
    const Position positionDiff = this->m_position - move;

    return this->isDefaultMove(positionDiff);
}

void Knight::move(const Position move, Piece *promotion, Board &board) {
    this->setPosition(move);
}

std::string Knight::getName() { return "Knight"; }
