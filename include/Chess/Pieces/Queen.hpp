#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Piece.hpp"

class Queen final : public Piece {
public:
    using Piece::Piece;

    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] bool canMove(Position move, Piece* captureCandidate, Piece* lastMovedPiece) override;
    [[nodiscard]] Type getType() const override;

};

#endif //QUEEN_HPP
