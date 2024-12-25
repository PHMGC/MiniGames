#include "Chess/Pieces/Pawn.h"


Pawn::Pawn(PieceTeam team, std::vector<int> position)
    : Piece(team, position) {
    std::string texturePath = (team == WHITE) ? "pawn_white.png" : "pawn_black.png";
    if (!m_texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Erro ao carregar a textura: " + texturePath);
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);
}

void Pawn::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}
