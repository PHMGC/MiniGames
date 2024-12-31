#include <stdexcept>

#include "Chess/Pieces/Pawn.hpp"

#include <Chess/Board.hpp>


// Checar se o movimento é o primeiro
bool Pawn::isDoubleMove(const Position move) const {
    if (this->isFirstMove) {
        if (this->m_team == Team::WHITE) {
            if (move.isEqual( 0, 2)) {
                return true;
            }
        }
        if (this->m_team == Team::BLACK) {
            if (move.isEqual( 0, -2)) {
                return true;
            }
        }
    }

    return false;
}

bool Pawn::isCapture(const Piece* captureCandidate) const {
    // Movimentos diagonais para capturar
    if (captureCandidate != nullptr
        && captureCandidate->getTeam() != this->m_team){
        if (const Position move = captureCandidate->getPosition();
            std::abs(move.getX()) == 1) {
            if ((this->m_team == Team::WHITE && move.getY() == 1)
                || (this->m_team == Team::BLACK && move.getY() == -1)) {
                return true;
                }
        }
    }
    return false;
}

// Checar se o movimento é de captura por En Passant
bool Pawn::isEnPassant(const Position move, Piece* lastMovedPiece) const {
    if (!lastMovedPiece || lastMovedPiece->getType() != Type::PAWN) {
    return false;
}
    const Pawn* lastPawn = dynamic_cast<const Pawn*>(lastMovedPiece);
    if (!lastPawn || !lastPawn->justDoubleMoved) {
        return false;
    }
    return (std::abs(move.getX()) == 1 && ((m_team == Team::WHITE && move.getY() == 1) || (m_team == Team::BLACK && move.getY() == -1)));
}

// Checar se o movimento levou o peão ao fim do tabuleiro
bool Pawn::isPromotion(const Position move) const {
    // Determinar a posição final do peão após o movimento
    int finalY = this->getPosition().getY() + move.getY();

    // Verificar se o peão atinge a última linha do tabuleiro
    if ((this->m_team == Team::WHITE && finalY == 7) ||
        (this->m_team == Team::BLACK && finalY == 0)) {
        return true;
        }

    return false;
}


bool Pawn::isDefaultMove(const Position move) {
    // Movimento padrão do peão
    if (this->m_team == Team::WHITE) {
        // Peão branco move para frente no eixo Y (1 unidade)
        if (move.isEqual(0, 1)) {
            return true;
        }

    } else if (this->m_team == Team::BLACK) {
        // Peão preto move para trás no eixo Y (-1 unidade)
        if (move.isEqual(0, -1)) {
            return true;
        }
    }
    return false;
}


// Checar se o movimento é valido
bool Pawn::canMove(const Position move, Piece* captureCandidate, Piece* lastMovedPiece) {
    const Position positionDiff = move - m_position;
    if (isDefaultMove(positionDiff)) {
        return true;
    }
    if (isDoubleMove(positionDiff)) {
        justDoubleMoved = true;
        return true;
    }
    if (isCapture(captureCandidate)) {
        return true;
    }
    if (isEnPassant(positionDiff, lastMovedPiece)) {
        return true;
    }

    return false;
}

void Pawn::move(const Position move, Piece* promotionPiece, Board& board) {
    this->isFirstMove = false;

    // Verificar se a promoção é possível
    if (this->isPromotion(move)) {
        if (promotionPiece != nullptr) {
            // Substituir o peão pela peça de promoção no tabuleiro
            board.setPieceAt(promotionPiece, this->getPosition());
        } else {
            throw std::invalid_argument("Promotion piece cannot be null");
        }
    } else {
        // Movimento normal do peão
        this->setPosition(move);
    }
}


Type Pawn::getType() const { return Type::PAWN; }
