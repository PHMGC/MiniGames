#ifndef PIECE_HPP
#define PIECE_HPP

#include <Chess/Board.hpp>

#include "Tools/Position.hpp"

enum Team { WHITE, BLACK };

class Piece {
public:
    Piece(Team team, const Position& position);
    virtual ~Piece() = default;

    [[nodiscard]] Team getTeam();
    [[nodiscard]] Position getPosition();
    void setPosition(const Position& position);
    friend std::ostream& operator<<(std::ostream& os, Piece& piece);

    // Métodos virtuais puros (devem ser implementados pelos herdeiros)
    virtual std::string getName() = 0;
    virtual void move(Position move, Piece *promotion, Board &board) = 0;
    [[nodiscard]] virtual bool canMove(Position move) = 0;
    [[nodiscard]] virtual bool isDefaultMove(Position move) = 0;

protected:
    Team m_team;
    Position m_position;
};

#endif
