#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn final : public Piece {
    bool isFirstMove = true;
    bool justDoubleMoved = false;
public:
    using Piece::Piece;


    void move(Position move, Piece *promotionPiece, Board &board) override;
    bool canMove(Position move, Piece *captureCandidate, Piece *lastMovedPiece) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] Type getType() const override;

    [[nodiscard]] bool isDoubleMove(Position move) const;
    [[nodiscard]] bool isCapture(const Piece* captureCandidate) const;
    [[nodiscard]] bool isEnPassant(Position move, Piece* lastMovedPiece) const;
    [[nodiscard]] bool isPromotion(Position move) const;
};

#endif //PAWN_HPP
