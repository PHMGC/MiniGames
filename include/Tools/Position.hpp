#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

class Position {
    int m_x, m_y;

public:
    // Construtores
    Position() : m_x(0), m_y(0) {}
    Position(int x, int y) : m_x(x), m_y(y) {}
    Position(const Position& other) = default;

    // Métodos getter e setter
    [[nodiscard]] int getX() const;
    void setX(int x);
    [[nodiscard]] int getY() const;
    void setY(int y);

    // Operadores
    [[nodiscard]] Position operator +(const Position& position) const;
    [[nodiscard]] Position operator-(const Position& position) const;
    Position& operator+=(const Position& position);
    Position& operator-=(const Position& position);
    friend std::ostream& operator<<(std::ostream& os, const Position& position);

    [[nodiscard]] bool isEqual(int x, int y) const;
    [[nodiscard]] bool isEqual(const Position& other) const;
};

#endif //POSITION_HPP
