#ifndef PAWN_HPP
#define PAWN_HPP

#include "Chess/Pieces/Piece.hpp"

class Pawn: public Piece {
    bool isFirstMove = true;
    bool justDoubleMoved = false;
public:
    using Piece::Piece;


    void move(Position move, Piece *promotion, Board &board) override;
    bool canMove(Position move, Piece *captured_piece, Piece *last_moved_piece) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] std::string getName() override;

    [[nodiscard]] bool isDoubleMove(Position move);
    [[nodiscard]] bool isCapture(Piece* captured_piece) const;
    [[nodiscard]] bool isEnPassant(Position move, Piece *last_moved_piece);
    [[nodiscard]] bool isPromotion(Position move);
};

#endif //PAWN_HPP
