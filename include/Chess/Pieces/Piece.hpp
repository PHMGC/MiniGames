#ifndef PIECE_HPP
#define PIECE_HPP

enum PieceTeam { WHITE, BLACK };

class Position{
public:
  int x;
  int y;
  Position(int x, int y);
};

class Piece {
public:
    Piece(PieceTeam team, std::vector<int> position);
    virtual ~Piece() = default;

protected:
    PieceTeam m_team;
    std::vector<int> m_position;
};

#endif