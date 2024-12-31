#ifndef TOWER_HPP
#define TOWER_HPP

#include "Piece.hpp"

class Tower final : public Piece {
    bool isFirstMove = true;
public:
    using Piece::Piece;

    void move(Position move, Piece *promotionPiece, Board &board) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] bool canMove(Position move, Piece* captureCandidate, Piece* lastMovedPiece) override;
    [[nodiscard]] Type getType() const override;

    [[nodiscard]] bool isCastle() const;

};

#endif //TOWER_HPP
