#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include <string>
#include <map>

using namespace std;

enum class Type {
    BISHOP = 'b',
    HORSE = 'n',
    KING = 'k',
    PAWN = 'p',
    QUEEN = 'q',
    TOWER = 'r'
};

enum class Team {
    BLACK = 'b',
    WHITE = 'w'
};

class Piece {
public:
    Type type;
    array<int, 2> pos;
    Team team;
    int size;
    sf::Texture texture;
    sf::Sprite sprite;

    Piece(Type type, array<int, 2> pos, Team team, int size) 
        : type(type), pos(pos), team(team), size(size) {
        string team_str = (team == Team::WHITE) ? "w" : "b";
        string type_str(1, static_cast<char>(type));
        texture.loadFromFile("source/" + team_str + "/" + type_str + ".png");
        sprite.setTexture(texture);
        sprite.setScale(static_cast<float>(size) / texture.getSize().x, 
                        static_cast<float>(size) / texture.getSize().y);
        sprite.setPosition(pos[0] * size, pos[1] * size);
    }
};

class Board {
public:
    array<int, 2> pos;
    int size;
    int piece_size;
    vector<Piece> pieces;

    Board(array<int, 2> pos, int size) 
        : pos(pos), size(size), piece_size(size / 8) {
        reset_board();
    }

    void reset_board() {
        pieces.clear();
        for (Team team : {Team::WHITE, Team::BLACK}) {
            int start_row_pawns = (team == Team::WHITE) ? 6 : 1;
            int start_row_major = (team == Team::WHITE) ? 7 : 0;

            for (int col = 0; col < 8; ++col) {
                pieces.emplace_back(Type::PAWN, array<int, 2>{col, start_row_pawns}, team, piece_size);
            }

            array<Type, 8> major_pieces_order = {
                Type::TOWER, Type::HORSE, Type::BISHOP,
                Type::QUEEN, Type::KING, Type::BISHOP,
                Type::HORSE, Type::TOWER
            };

            for (int col = 0; col < 8; ++col) {
                pieces.emplace_back(major_pieces_order[col], array<int, 2>{col, start_row_major}, team, piece_size);
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                sf::RectangleShape rect(sf::Vector2f(piece_size, piece_size));
                rect.setPosition(pos[0] + col * piece_size, pos[1] + row * piece_size);
                rect.setFillColor((row + col) % 2 == 0 ? sf::Color(162, 81, 77) : sf::Color(241, 231, 230));
                window.draw(rect);
            }
        }
        for (Piece& piece : pieces) {
            window.draw(piece.sprite);
        }
    }
};

