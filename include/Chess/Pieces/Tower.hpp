#ifndef TOWER_HPP
#define TOWER_HPP

#include "Chess/Pieces/Piece.hpp"

class Tower final : public Piece {
    bool isFirstMove = true;
public:
    using Piece::Piece;

    void move(Position move, Piece *promotion, Board &board) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] bool canMove(Position move) override;
    [[nodiscard]] std::string getName() override;

    bool isCastle();

};

#endif //TOWER_HPP