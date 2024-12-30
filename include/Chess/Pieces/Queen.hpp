#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Chess/Pieces/Piece.hpp"

class Queen final : public Piece {
public:
    using Piece::Piece;

    void move(Position move, Piece *promotion, Board &board) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] bool canMove(Position move) override;
    [[nodiscard]] std::string getName() override;

};

#endif //QUEEN_HPP
