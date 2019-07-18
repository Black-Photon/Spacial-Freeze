#include <iostream>
#include "../headers/logger.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

namespace logger {
    void message(const string& s) noexcept(true) {
        cout << "[INFO] " << s << endl;
    }

    void warn(const string& s) noexcept(true) {
        cout << "[WARN] " << s << endl;
    }

    void error(const string& s) noexcept(true) {
        cerr << "[ERROR] " << s << endl;
    }

    // Use only for the last error printed
    void fatal(const string& s) noexcept(true) {
        cerr << "[FATAL] " << s << endl;
    }
}