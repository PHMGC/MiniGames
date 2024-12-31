#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

#include <Chess/Pieces.hpp>

class Board {
    std::vector<Piece*> m_pieces;
    Team turn = Team::WHITE;
    void initializeTeam(Team team);

    public:
    Board();
    ~Board();

    void print() const;

    static bool isPositionValid(const Position& pos);
    // Verificar se há uma peça na posição
    [[nodiscard]] bool hasPieceAt(const Position& pos) const;
    // Acessar a peça na posição
    [[nodiscard]] Piece* getPieceAt (const Position &pos) const;
    void setPieceAt(Piece *piece, Position pos);

    [[nodiscard]] Team getTurn() const;
    void changeTurn();

};

#endif //BOARD_HPP
