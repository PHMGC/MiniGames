#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece {
public:
    Pawn(PieceTeam team, std:vector position);
    void draw(sf::RenderWindow& window) override;
};

#endif
