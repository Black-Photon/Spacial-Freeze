#ifndef SPACIALFREEZE_LOGGER_H
#define SPACIALFREEZE_LOGGER_H

#include <iostream>

using std::string;

namespace logger {
    void message(const string& s) noexcept(true);
    void warn(const string& s) noexcept(true);
    void error(const string& s) noexcept(true);
    // Use only for the last error printed
    void fatal(const string& s) noexcept(true);
}

#endif //SPACIALFREEZE_LOGGER_H
