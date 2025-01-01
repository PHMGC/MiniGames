#ifndef GAME_HPP
#define GAME_HPP

#include "Chess/Board.hpp"


class Chess {
    Board *board;
    Team turn = Team::WHITE;
    public:
    Chess();

    [[nodiscard]] Team getTurn() const;
    void changeTurn();

    void printBoard() const;
};



#endif //GAME_HPP
