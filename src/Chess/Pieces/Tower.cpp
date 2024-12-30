#include <stdexcept>

#include "Chess/Pieces/Tower.hpp"

bool Tower::isDefaultMove(Position move) {
    // Movimento padrão da torre
    return move.getX() == 0 || move.getY() == 0;
}

bool Tower::isCastle() {
    // Checar se a torre moveu
    return this->isFirstMove;
}

// Checar se o movimento é valido
bool Tower::canMove(const Position move) {
    const Position positionDiff = this->m_position - move;

    return this->isDefaultMove(positionDiff)
        || this->isCastle();
}

void Tower::move(const Position move, Piece *promotion, Board &board) {
    this->isFirstMove = false;
    this->setPosition(move);
}

std::string Tower::getName() { return "Tower"; }
