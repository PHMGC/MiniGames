#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"


class Knight final: public Piece {
public:
    using Piece::Piece;

    [[nodiscard]] bool canMove(Position move, Piece* captureCandidate, Piece* lastMovedPiece) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] Type getType() const override;


};

#endif //KNIGHT_HPP
