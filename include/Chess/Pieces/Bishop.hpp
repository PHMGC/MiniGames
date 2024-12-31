#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop final : public Piece {
public:
    using Piece::Piece;

    [[nodiscard]] bool canMove(Position move, Piece* captureCandidate, Piece* lastMovedPiece) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] Type getType() const override;

};

#endif //BISHOP_HPP
