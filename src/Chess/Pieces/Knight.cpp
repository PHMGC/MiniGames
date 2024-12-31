#include <stdexcept>

#include "Chess/Pieces/Knight.hpp"

bool Knight::isDefaultMove(const Position move) {
    // Movimento padrão do cavalo
    return move.isEqual(2, 1) || move.isEqual(1, 2);
}

// Checar se o movimento é valido
bool Knight::canMove(const Position move, Piece* captureCandidate, Piece* lastMovedPiece) {
    const Position positionDiff = this->m_position - move;

    return this->isDefaultMove(positionDiff);
}

Type Knight::getType() const { return Type::KNIGHT; }
