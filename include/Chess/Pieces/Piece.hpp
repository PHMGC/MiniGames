#ifndef PIECE_HPP
#define PIECE_HPP


#include "Tools/Position.hpp"

class Board;


enum class Team { WHITE, BLACK };
enum class Type { BISHOP, KING, KNIGHT, PAWN, QUEEN, ROOK, UNKNOWN };
char typeToSymbol(Type type, Team team);

class Piece {
public:

    Piece(Team team, const Position& position);
    virtual ~Piece() = default;

    [[nodiscard]] Team getTeam() const;
    [[nodiscard]] Position getPosition() const;
    void setPosition(const Position& position);
    friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
    [[nodiscard]] virtual Type getType() const;
    virtual void move(Position move, Piece *promotion, Board &board);

    // Métodos virtuais puros (devem ser implementados pelos herdeiros)
    [[nodiscard]] virtual bool canMove(Position move, Piece* captureCandidate, Piece* lastMovedPiece) = 0;
    [[nodiscard]] virtual bool isDefaultMove(Position move) = 0;

protected:
    Team m_team;
    Position m_position;
};

#endif
