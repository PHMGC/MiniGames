#include <stdexcept>

#include "Chess/Pieces/Bishop.hpp"

bool Bishop::isDefaultMove(Position move) {
    // Movimento padrão do bispo
    return std::abs(move.getX()) == std::abs(move.getY());
}

// Checar se o movimento é valido
bool Bishop::canMove(const Position move) {
    const Position positionDiff = this->m_position - move;

    return this->isDefaultMove(positionDiff);
}

void Bishop::move(const Position move) {
      this->setPosition(move);
}

std::string Bishop::getName() { return "Bishop"; }

