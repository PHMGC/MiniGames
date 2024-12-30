#include <stdexcept>

#include "Chess/Pieces/Pawn.hpp"

#include <Chess/Board.hpp>


// Checar se o movimento é o primeiro
bool Pawn::isDoubleMove(const Position move){
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

bool Pawn::isCapture(Piece* captured_piece) const {
    // Movimentos diagonais para capturar
    if (captured_piece != nullptr
        && captured_piece->getTeam() != this->m_team){
        if (const Position move = captured_piece->getPosition();
            std::abs(move.getX()) == 1) {
            if ((this->m_team == WHITE && move.getY() == 1)
                || (this->m_team == BLACK && move.getY() == -1)) {
                return true;
                }
        }
    }
    return false;
}

// Checar se o movimento é de captura por En Passant
bool Pawn::isEnPassant(Position move, Piece* last_moved_piece) {
    // Verificar se existe uma peça movida anteriormente
    if (last_moved_piece == nullptr) {
        return false;
    }

    // Verificar se o movimento é diagonal para "En Passant"
    if ((this->m_team == WHITE && move.getY() == 1) ||
        (this->m_team == BLACK && move.getY() == -1)) {

        // Checar se a última peça movida foi um peão do time oposto
        if (last_moved_piece->getName() == "Pawn" && last_moved_piece->getTeam() != this->m_team) {
            Pawn* last_moved_pawn = dynamic_cast<Pawn*>(last_moved_piece);

            // Garantir que o peão fez o movimento duplo recentemente
            if (last_moved_pawn != nullptr && last_moved_pawn->justDoubleMoved) {
                return true;
            }
        }
        }
    return false;
}

// Checar se o movimento levou o peão ao fim do tabuleiro
bool Pawn::isPromotion(const Position move) {
    // Determinar a posição final do peão após o movimento
    int finalY = this->getPosition().getY() + move.getY();

    // Verificar se o peão atinge a última linha do tabuleiro
    if ((this->m_team == WHITE && finalY == 7) ||
        (this->m_team == BLACK && finalY == 0)) {
        return true;
        }

    return false;
}


bool Pawn::isDefaultMove(const Position move) {
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
bool Pawn::canMove(const Position move, Piece* captured_piece,  Piece* last_moved_piece) {
    const Position positionDiff = this->m_position - move;

    if (this->isDoubleMove(positionDiff)) {
        this->justDoubleMoved = true;
        return true;
    }
    return this->isEnPassant(positionDiff, last_moved_piece)
           || this->isCapture(captured_piece)
           || this->isDefaultMove(positionDiff);
}

void Pawn::move(const Position move, Piece* promotion, Board& board) {
    this->isFirstMove = false;

    // Verificar se a promoção é possível
    if (this->isPromotion(move)) {
        if (promotion != nullptr) {
            // Substituir o peão pela peça de promoção no tabuleiro
            board.setPieceAt(this, promotion);
        } else {
            throw std::invalid_argument("Promotion piece cannot be null");
        }
    } else {
        // Movimento normal do peão
        this->setPosition(move);
    }
}


std::string Pawn::getName() { return "Pawn"; }
