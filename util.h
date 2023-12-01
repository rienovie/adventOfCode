#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace util {
    std::vector< std::string > getInput(const char* fileLocation);

    template <typename T>
    void qPrint(T output);
}
