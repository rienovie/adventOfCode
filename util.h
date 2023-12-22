#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace util {
    std::vector< std::string > getInput(const char* fileLocation);
    int strToInt(std::string str);

    //quick print
    template <typename T>
    void qPrint(T output) {
        std::cout << output << "\n";
    }
    template <typename T, typename... Args>
    void qPrint(T output, Args... args){
        std::cout << output << " ";
        qPrint(args...);
    }

    template <typename T>
    bool searchVector(std::vector<T>& inputVector, T toFind) {
        for(T toCheck : inputVector){
            if(toCheck == toFind) { return true; }
        }
        return false;
    }

}
