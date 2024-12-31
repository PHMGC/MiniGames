#include <iomanip>
#include <Chess/Board.hpp>

void Board:: initializeTeam(const Team team) {
    const int backRow = (team == Team::WHITE) ? 0 : 7;
    const int pawnRow = (team == Team::WHITE) ? 1 : 6;

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
    initializeTeam(Team::WHITE);
    initializeTeam(Team::BLACK);
}
Board::~Board() {
    for (auto& piece : this->m_pieces) {
        if (piece) { // Verifica se o ponteiro não é nullptr
            delete piece;
            piece = nullptr; // Opcional: evita ponteiros pendentes
        }
    }
}

void Board::print() const {
    // Imprime o cabeçalho
    std::cout << "  ";
    for (char col = 'a'; col <= 'h'; ++col) {
        std::cout << std::setw(6) << col;
    }
    std::cout << std::endl;

    for (int y = 7; y >= 0; --y) {
        std::cout << " " << y + 1 << " ";
        for (int x = 0; x < 8; ++x) {
            if (const Piece* piece = this->getPieceAt(Position(x, y))) {
                std::cout << std::setw(4)
                          << (piece->getTeam() == Team::WHITE ? "W" : "B")
                          << typeToString(piece->getType()).substr(0, 2);
            } else {
                std::cout << std::setw(6) << "---";
            }
        }
        std::cout << std::endl;
    }
}




bool Board::isPositionValid(const Position& pos) {
    return pos.getX() >= 0 && pos.getX() < 8 && pos.getY() >= 0 && pos.getY() < 8;
}

// Verificar se há uma peça na posição
bool Board::hasPieceAt(const Position& pos) const {
    return this->getPieceAt(pos) != nullptr;
}


// Acessar a peça na posição
Piece* Board::getPieceAt (const Position &pos) const {
    if (!isPositionValid(pos)) {
        throw std::out_of_range("Posição fora do tabuleiro.");
    }
    return this->m_pieces[pos.getY() * 8 + pos.getX()];
}


void Board::setPieceAt(Piece* piece, const Position pos) {
    if (!isPositionValid(pos)) {
        throw std::out_of_range("Posição fora do tabuleiro.");
    }
    this->m_pieces[pos.getY() * 8 + pos.getX()] = piece;
}

Team Board::getTurn() {
    return this->turn;
}

void Board::changeTurn() {
    this->turn = this->getTurn() == Team::WHITE ? Team::BLACK : Team::WHITE;
}
