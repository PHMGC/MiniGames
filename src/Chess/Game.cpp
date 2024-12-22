#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include <iostream>
#include <thread>
#include <chrono>
#include "header.h"

using namespace std;

class Game {
public:
    static const int MAX_STEPS = 8;

    Game(Board* board) : board(board), curTurn(Team::WHITE), ended(false) {}

    bool isWithinBoard(const sf::Vector2i& pos) {
        return pos.x >= 0 && pos.x < 8 && pos.y >= 0 && pos.y < 8;
    }

    Piece* pieceByPos(const sf::Vector2i& pos) {
        for (auto& piece : board->pieces) {
            if (piece.pos == pos) {
                return &piece;
            }
        }
        return nullptr;
    }

    vector<sf::Vector2i> pawnMoves(Piece* pawn) {
        if (pawn->type != Type::PAWN) {
            throw invalid_argument("Piece is not a pawn!");
        }

        vector<sf::Vector2i> moves;
        int direction = (pawn->team == Team::WHITE) ? -1 : 1;

        // Movimento normal
        sf::Vector2i forwardPos = pawn->pos + sf::Vector2i(0, direction);
        if (isWithinBoard(forwardPos) && !pieceByPos(forwardPos)) {
            moves.push_back(forwardPos);
        }

        // Movimento de dois passos
        int startRow = (pawn->team == Team::WHITE) ? 6 : 1;
        if (pawn->pos.y == startRow) {
            sf::Vector2i forwardTwoPos = pawn->pos + sf::Vector2i(0, 2 * direction);
            sf::Vector2i intermediatePos = pawn->pos + sf::Vector2i(0, direction);
            if (isWithinBoard(forwardTwoPos) && !pieceByPos(forwardTwoPos) && !pieceByPos(intermediatePos)) {
                moves.push_back(forwardTwoPos);
            }
        }

        // Captura
        array<sf::Vector2i, 2> capturePositions = {
            pawn->pos + sf::Vector2i(-1, direction),
            pawn->pos + sf::Vector2i(1, direction)
        };
        for (const auto& capturePos : capturePositions) {
            Piece* capturedPiece = pieceByPos(capturePos);
            if (isWithinBoard(capturePos) && capturedPiece && capturedPiece->team == enemyTurn()) {
                moves.push_back(capturePos);
            }
        }

        return moves;
    }

    vector<sf::Vector2i> moves(Piece* piece) {
        if (!piece) {
            return {};
        }

        if (piece->type == Type::PAWN) {
            return pawnMoves(piece);
        }

        Team enemy = enemyTurn();
        int steps = (piece->type == Type::HORSE || piece->type == Type::KING) ? 1 : MAX_STEPS;
        vector<sf::Vector2i> moves;

        for (const auto& direction : DIRECTIONS[piece->type]) {
            for (int step = 1; step <= steps; ++step) {
                sf::Vector2i newPos = piece->pos + step * direction;
                if (isWithinBoard(newPos)) {
                    Piece* pieceAtPos = pieceByPos(newPos);
                    if (!pieceAtPos) {
                        moves.push_back(newPos);
                    } else if (pieceAtPos->team == enemy) {
                        moves.push_back(newPos);
                        break;
                    } else {
                        break;
                    }
                }
            }
        }

        return moves;
    }

    void debugBoardMoves() {
        for (const auto& piece : board->pieces) {
            cout << piece.team << " " << piece.type << " " << piece.pos.x << "," << piece.pos.y << " -> ";
            auto pieceMoves = moves(&piece);
            for (const auto& move : pieceMoves) {
                cout << "(" << move.x << "," << move.y << ") ";
            }
            cout << "\n";
        }
    }

    bool makeMove(Piece* piece, const sf::Vector2i& move) {
        if (ended) return false;

        if (piece->team != curTurn) {
            cout << "It's " << curTurn << "'s turn\n";
            return false;
        }

        auto validMoves = moves(piece);
        if (find(validMoves.begin(), validMoves.end(), move) == validMoves.end()) {
            cout << "Invalid move\n";
            return false;
        }

        Piece* target = pieceByPos(move);
        if (target) {
            if (target->team == piece->team) {
                cout << "Friendly fire detected\n";
                return false;
            } else {
                auto it = find(board->pieces.begin(), board->pieces.end(), *target);
                if (it != board->pieces.end()) {
                    board->pieces.erase(it);
                }
            }
        }

        piece->pos = move;
        changeTurn();
        return true;
    }

    Team enemyTurn() {
        return (curTurn == Team::WHITE) ? Team::BLACK : Team::WHITE;
    }

    void changeTurn() {
        if (checkmate()) {
            ended = true;
            cout << curTurn << " wins!\n";
            this_thread::sleep_for(chrono::seconds(3));
            resetGame();
        } else {
            curTurn = enemyTurn();
        }
    }

    bool checkmate() {
        for (const auto& piece : board->pieces) {
            if (piece.type == Type::KING && piece.team == enemyTurn()) {
                return false;
            }
        }
        return true;
    }

    void resetGame() {
        board->resetBoard();
        ended = false;
    }

private:
    Board* board;
    Team curTurn;
    bool ended;

    static const map<Type, vector<sf::Vector2i>> DIRECTIONS;
};

const map<Type, vector<sf::Vector2i>> Game::DIRECTIONS = {
    {Type::BISHOP, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
    {Type::TOWER, {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}},
    {Type::QUEEN, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}},
    {Type::KING, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}},
    {Type::HORSE, {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}}}
};
