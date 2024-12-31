#include "Chess/Pieces/Piece.hpp"


std::string typeToString(const Type type) {
    switch (type) {
        case Type::BISHOP: return "Bishop";
        case Type::KING: return "King";
        case Type::KNIGHT: return "Knight";
        case Type::PAWN: return "Pawn";
        case Type::QUEEN: return "Queen";
        case Type::TOWER: return "Tower";
        default: return "Unknown";
    }
}


Piece::Piece(const Team team, const Position& position)
        : m_team(team), m_position(position) {}

Team Piece::getTeam() const { return this->m_team; }

Position Piece::getPosition() const { return this->m_position; }

void Piece::setPosition(const Position& position) { this->m_position = position; }

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << "(" << (piece.getTeam() == Team::WHITE ? "White" : "Black")
       << " " << typeToString(piece.getType())
       << " at " << piece.getPosition() << ")";
    return os;
}

Type Piece::getType() const { return Type::UNKNOWN; }

void Piece::move(const Position move, Piece *promotion, Board &board) {
    this->setPosition(move);
}

