#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace util {
    std::vector< std::string > getInput(const char* fileLocation);
    int strToInt(std::string str);

    template <typename T>
    void qPrint(T output);

    template <typename T>
    void qPrint(T output0, T output1);

    template <typename C, typename T>
    void qPrint(C output0, T output1);
}
