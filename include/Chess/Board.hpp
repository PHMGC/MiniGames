#ifndef BOARD_HPP
#define BOARD_HPP

#include <memory>
#include <vector>

#include <Chess/Pieces.hpp>

class Board {
    std::vector<Piece*> m_pieces;
    void initializeTeam(Team team);

    public:
    Board();
    ~Board();

    static bool Board::isPositionValid(const Position& pos) ;
    // Verificar se há uma peça na posição
    [[nodiscard]] bool hasPieceAt(const Position& pos) const;
    // Acessar a peça na posição
    [[nodiscard]] Piece* getPieceAt (const Position &pos) const;
    void setPieceAt(Piece *piece, Position pos);
    void print() const;

    // [[nodiscard]] std::vector<<Piece> Board::getPieces() const;

};

#endif //BOARD_HPP
