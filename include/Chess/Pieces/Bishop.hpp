#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Chess/Pieces/Piece.hpp"

class Bishop final : public Piece {
public:
    using Piece::Piece;

    void move(Position move, Piece *promotion, Board &board) override;
    [[nodiscard]] bool canMove(Position move) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] std::string getName() override;

};

#endif //BISHOP_HPP
