#include "Chess/Pieces/Piece.hpp"


Piece::Piece(Team team, const Position& position)
        : m_team(team), m_position(position) {}

Team Piece::getTeam() { return this->m_team; }

Position Piece::getPosition() { return this->m_position; }

void Piece::setPosition(const Position& position) { this->m_position = position; }

std::string Piece::getName() { return "Piece"; }

std::ostream& operator<<(std::ostream& os, Piece& piece) {
    os << "(" << (piece.getTeam() == WHITE ? "White" : "Black")
       << " " << piece.getName()
       << " at " << piece.getPosition() << ")";
    return os;
}

