#include "util.h"


namespace util {

    std::vector <std::string> getInput(const char* fileLocation){
        std::ifstream file;
        file.open(fileLocation);

        std::vector<std::string> output;
        std::string line;

        while(getline(file, line)){
            output.push_back(line);
        }
        file.close();

        return output;

    }

    //this always seems to happen whenever I try to use this
    //so hopefully this makes it less annoying everytime
    int strToInt(std::string str){
        try{
            return std::stoi(str);
        } catch (...){
            std::string eStr = "ERROR using stoi! ";
            eStr.append("Attempted string:");
            qPrint(eStr,str);
        }
        return -1;
    }

    //quick print
    template <typename T>
    void qPrint(T output) {
        std::cout << output << "\n";
    }
    template <typename T>
    void qPrint(T output0, T output1){
        std::cout << output0 << " " << output1 << "\n";
    }

    template <typename C, typename T>
    void qPrint(C output0, T output1){
        std::cout << output0 << " " << output1 << "\n";
    }

    //this is ugly, will look up if there's something better
    template void qPrint<int>(int);
    template void qPrint<float>(float);
    template void qPrint<char const*>(char const*);
    template void qPrint<char const*>(char const*, char const*);
    template void qPrint<std::string>(std::string);
    template void qPrint<char>(char);
    template void qPrint<std::string>(std::string, std::string);
    template void qPrint<char const*, int>(char const*, int);
    template void qPrint<int>(int, int);
    template void qPrint<char const*, std::string>(char const*, std::string);
    template void qPrint<char const*, unsigned long>(char const*, unsigned long);
    template void qPrint<ulong>(ulong);
    template void qPrint<uint>(uint);
    template void qPrint<long>(long);
    template void qPrint<long long>(long long);


}
