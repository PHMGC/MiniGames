#ifndef PIECE_H
#define PIECE_H

#include <string>

enum class Type { BISHOP, HORSE, KING, PAWN, QUEEN, TOWER };
enum class Team { BLACK, WHITE };

class Piece {
public:
    Type type;
    Team team;
    std::pair<int, int> pos;
    int size;

    Piece(Type type, std::pair<int, int> pos, Team team, int size);

    std::string getImagePath() const; // Retorna o caminho da imagem.
};

#endif
