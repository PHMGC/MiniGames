#include <stdexcept>

#include "Chess/Pieces/Queen.hpp"

bool Queen::isDefaultMove(Position move) {
    // Movimento padrão da rainha
    return (move.getX() == 0 || move.getY() == 0)
        || (std::abs(move.getX()) == std::abs(move.getY()));
}

// Checar se o movimento é valido
bool Queen::canMove(const Position move) {
    const Position positionDiff = this->m_position - move;

    return this->isDefaultMove(positionDiff);
}

void Queen::move(const Position move) {
    this->setPosition(move);
}

std::string Queen::getName() { return "Queen"; }
