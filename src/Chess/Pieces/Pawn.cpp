#include <stdexcept>

#include "Chess/Pieces/Pawn.hpp"

// Checar se o movimento é o primeiro
bool Pawn::isDoubleMove(Position move){
    if (this->isFirstMove) {
        if (this->m_team == WHITE) {
            if (move.isEqual( 0, 2)) {
                return true;
            }
        }
        if (this->m_team == BLACK) {
            if (move.isEqual( 0, -2)) {
                return true;
            }
        }
    }

    return false;
}

bool Pawn::isCapture(Position move) {
    // Movimentos diagonais para capturar
    if (std::abs(move.getX()) == 1){
        if ((this->m_team == WHITE && move.getY() == 1)
            || (this->m_team == BLACK && move.getY() == -1)) {
            // TODO
            // Aqui você pode verificar se existe uma peça inimiga na posição
            // Isso depende de como o tabuleiro é gerenciado
            return true;
            }
    }
    return false;
}

// Checar se o movimento é de captura por En Passant
bool Pawn::isEnPassant()  {
    // TODO
    // if (this->isFirstMove){
    //
    // }
    return false;
}

// Checar se o movimento levou o peão ao fim do tabuleiro
bool Pawn::isPromotion(){
    // TODO
    // if ()
    return false;
}

bool Pawn::isDefaultMove(Position move) {
    // Movimento padrão do peão
    if (this->m_team == WHITE) {
        // Peão branco move para frente no eixo Y (1 unidade)
        if (move.isEqual(0, 1)) {
            return true;
        }

    } else if (this->m_team == BLACK) {
        // Peão preto move para trás no eixo Y (-1 unidade)
        if (move.isEqual(0, -1)) {
            return true;
        }
    }
    return false;
}

// Checar se o movimento é valido
bool Pawn::canMove(const Position move) {
    const Position positionDiff = this->m_position - move;

    return this->isDoubleMove(positionDiff)
           || this->isEnPassant()
           || this->isCapture(positionDiff)
           || this->isPromotion()
           || this->isDefaultMove(positionDiff);
}

void Pawn::move(const Position move) {
    this->isFirstMove = false;
    this->setPosition(move);
}

std::string Pawn::getName() { return "Pawn"; }
