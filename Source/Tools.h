#pragma once

#include <string>
#include <stdexcept>
#include <sstream>
#include <cstdio>
#include <fmt/core.h>

inline void __errChk(int error, const char* func, int line, const std::string& msg) {
    if (error != 0) {
        std::ostringstream oss;
        oss << "(" << error << ") " << func << " line:" << line << "\n" << msg << "\n";
        throw std::runtime_error(oss.str());
    }
}

// TODO figure out the best way to handle errors.
#define ERR_CHK(fnCall, ...) \
    __errChk((fnCall), __func__, __LINE__, fmt::format(__VA_ARGS__))
