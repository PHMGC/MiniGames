#include "Tools/Terminal.hpp"
#include "windows.h"

// Cores
const std::string Terminal::GREEN = Terminal::supportsAnsiColors() ? "\033[32m" : "";
const std::string Terminal::BLUE = Terminal::supportsAnsiColors() ? "\033[34m" : "";
const std::string Terminal::DEFAULT = Terminal::supportsAnsiColors() ? "\033[0m" : "";

// Implementação da função supportsAnsiColors
bool Terminal::supportsAnsiColors() {
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    return h != INVALID_HANDLE_VALUE && GetConsoleMode(h, &mode) &&
           SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#else
    return true;
#endif
}
