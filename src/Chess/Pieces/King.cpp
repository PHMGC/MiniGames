#include <stdexcept>

#include "Chess/Pieces/King.hpp"

#include <Chess/Board.hpp>

bool King::isDefaultMove(const Position move) {
    // Movimento padrão do rei
    return std::abs(move.getX()) == std::abs(move.getY())
           && std::abs(move.getX()) <= 1
           && std::abs(move.getY()) <= 1;

}

bool King::isCastle() const {
    // Checar se o rei moveu
    return this->isFirstMove;
}


// Checar se o movimento é valido
bool King::canMove(const Position move, Piece* captureCandidate, Piece* lastMovedPiece) {
    const Position positionDiff = this->m_position - move;

    return this->isDefaultMove(positionDiff)
           || this->isCastle();
}

void King::move(const Position move, Piece *promotionPiece, Board &board) {
    this->isFirstMove = false;
    this->setPosition(move);
}

Type King::getType() const { return Type::KING; }
