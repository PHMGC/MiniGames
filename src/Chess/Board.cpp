#include <Chess/Board.hpp>

void Board:: initializeTeam(Team team) {
    int backRow = (team == WHITE) ? 0 : 7;
    int pawnRow = (team == WHITE) ? 1 : 6;

    // Linha de trás
    this->m_pieces[backRow * 8 + 0] = new Tower(team, Position(0, backRow)); // Torre
    this->m_pieces[backRow * 8 + 1] = new Knight(team, Position(1, backRow)); // Cavalo
    this->m_pieces[backRow * 8 + 2] = new Bishop(team, Position(2, backRow)); // Bispo
    this->m_pieces[backRow * 8 + 3] = new Queen(team, Position(3, backRow)); // Rainha
    this->m_pieces[backRow * 8 + 4] = new King(team, Position(4, backRow)); // Rei
    this->m_pieces[backRow * 8 + 5] = new Bishop(team, Position(5, backRow)); // Bispo
    this->m_pieces[backRow * 8 + 6] = new Knight(team, Position(6, backRow)); // Cavalo
    this->m_pieces[backRow * 8 + 7] = new Tower(team, Position(7, backRow)); // Torre

    // Linha de peões
    for (int x = 0; x < 8; ++x) {
        this->m_pieces[pawnRow * 8 + x] = new Pawn(team, Position(x, pawnRow));
    }
}

Board::Board() : m_pieces(64, nullptr) {
    initializeTeam(WHITE);
    initializeTeam(BLACK);
}
Board::~Board() {
    for (auto& piece : this->m_pieces) {
        if (piece) { // Verifica se o ponteiro não é nullptr
            delete piece;
            piece = nullptr; // Opcional: evita ponteiros pendentes
        }
    }
}


// Acessar a peça na posição
Piece* Board::getPieceAt (const Position &pos) const {
    if (pos.getX() < 0 || pos.getX() >= 8 || pos.getY() < 0 || pos.getY() >= 8) {
        throw std::out_of_range("Posicao fora do tabuleiro.");
    }
    return this->m_pieces[pos.getY() * 8 + pos.getX()];
}


// Verificar se há uma peça na posição
bool Board::hasPieceAt(const Position& pos) const {
    return this->getPieceAt(pos) != nullptr;
}

// std::vector<std::unique_ptr<Piece>> Board::getPieces() const {
//     return this->m_pieces;
// }

