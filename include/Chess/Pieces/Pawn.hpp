#ifndef PAWN_HPP
#define PAWN_HPP

#include "Chess/Pieces/Piece.hpp"

class Pawn final: public Piece {
    bool isFirstMove = true;
public:
    using Piece::Piece;


    void move(Position move) override;
    [[nodiscard]] bool canMove(Position move) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] std::string getName() override;

    [[nodiscard]] bool isDoubleMove(Position move);
    [[nodiscard]] bool isCapture(Position move);
    [[nodiscard]] bool isEnPassant();
    [[nodiscard]] bool isPromotion();
};

#endif //PAWN_HPP
