#include "Chess/Pieces/Rook.hpp"

bool Rook::isDefaultMove(const Position move) {
    // Movimento padrão da torre
    return move.getX() == 0 || move.getY() == 0;
}

bool Rook::isCastle() const {
    // Checar se a torre moveu
    return this->isFirstMove;
}

// Checar se o movimento é valido
bool Rook::canMove(const Position move, Piece* captureCandidate, Piece* lastMovedPiece) {
    const Position positionDiff = this->m_position - move;

    return this->isDefaultMove(positionDiff)
        || this->isCastle();
}

void Rook::move(const Position move, Piece *promotionPiece, Board &board) {
    this->isFirstMove = false;
    this->setPosition(move);
}

Type Rook::getType() const { return Type::ROOK; }
