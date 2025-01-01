#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <string>

class Terminal {
public:
    // Tentativa de habilitar cor no terminal
    static bool supportsAnsiColors();

    // Cores
    static const std::string GREEN;
    static const std::string BLUE;
    static const std::string DEFAULT;
};

#endif // TERMINAL_HPP
