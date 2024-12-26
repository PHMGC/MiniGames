#include "Tools/Position.hpp"


// Métodos getter e setter
int Position::getX() const { return this->m_x; }
void Position::setX(int x) { this->m_x = x; }
int Position::getY() const { return this->m_y; }
void Position::setY(int y) { this->m_y = y; }

// Operadores
Position Position::operator +(const Position& position) const {
    return {this->m_x + position.getX(), this->m_y + position.getY()};
}

Position Position::operator-(const Position& position) const {
    return {this->m_x - position.getX(), this->m_y - position.getY()};
}

Position& Position::operator+=(const Position& position) {
    this->m_x += position.getX();
    this->m_y += position.getY();
    return *this;
}

Position& Position::operator-=(const Position& position) {
    this->m_x -= position.getX();
    this->m_y -= position.getY();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Position& position){
    os << "(" << position.getX() << ", " << position.getY() << ")";
    return os;
}

bool Position::isEqual(int x, int y) const {
    return this->m_x == x && this->m_y == y;
}

bool Position::isEqual(const Position& other) const {
    return this->m_x == other.getX() && this->m_y == other.getY();
}