#include "Chess/Pieces/Piece.hpp"


char typeToSymbol(const Type type, const Team team) {
    char symbol;
    switch (type) {
        case Type::PAWN:   symbol = 'P'; break;
        case Type::ROOK:   symbol = 'R'; break;
        case Type::KNIGHT: symbol = 'N'; break;
        case Type::BISHOP: symbol = 'B'; break;
        case Type::QUEEN:  symbol = 'Q'; break;
        case Type::KING:   symbol = 'K'; break;
        default:           symbol = '?'; break;
    }
    // Letras minúsculas para pretas, maiúsculas para brancas
    if (team == Team::BLACK) {
        symbol = std::tolower(symbol);
    }
    return symbol;
}


Piece::Piece(const Team team, const Position& position)
        : m_team(team), m_position(position) {}

Team Piece::getTeam() const { return this->m_team; }

Position Piece::getPosition() const { return this->m_position; }

void Piece::setPosition(const Position& position) { this->m_position = position; }

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << typeToSymbol(piece.getType(), piece.getTeam());
    return os;
}

Type Piece::getType() const { return Type::UNKNOWN; }

void Piece::move(const Position move, Piece *promotion, Board &board) {
    this->setPosition(move);
}

