#include <stdexcept>

#include "Chess/Pieces/Bishop.hpp"

bool Bishop::isDefaultMove(const Position move) {
    // Movimento padrão do bispo
    return std::abs(move.getX()) == std::abs(move.getY());
}

// Checar se o movimento é valido
bool Bishop::canMove(const Position move, Piece* captureCandidate, Piece* lastMovedPiece) {
    const Position positionDiff = this->m_position - move;

    return this->isDefaultMove(positionDiff);
}

Type Bishop::getType() const { return Type::BISHOP; }

