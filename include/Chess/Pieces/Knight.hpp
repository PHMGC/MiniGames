#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Chess/Pieces/Piece.hpp"

class Knight final: public Piece {
public:
    using Piece::Piece;

    void move(Position move, Piece *promotion, Board &board) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] bool canMove(Position move) override;
    [[nodiscard]] std::string getName() override;


};

#endif //KNIGHT_HPP
