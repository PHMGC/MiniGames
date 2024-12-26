#ifndef KING_HPP
#define KING_HPP

#include "Chess/Pieces/Piece.hpp"

class King final : public Piece {
    bool isFirstMove = true;
public:
    using Piece::Piece;

    void move(Position move) override;
    [[nodiscard]] bool isDefaultMove(Position move) override;
    [[nodiscard]] bool canMove(Position move) override;
    [[nodiscard]] std::string getName() override;

    bool isCastle() const;

};

#endif //KING_HPP
