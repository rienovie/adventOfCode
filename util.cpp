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

    //quick print
    template <typename T>
    void qPrint(T output) {
        std::cout << output << "\n";
    }

    template void qPrint<int>(int);
    template void qPrint<float>(float);
    template void qPrint<char const*>(char const*);
    template void qPrint<std::string>(std::string);
    template void qPrint<char>(char);


}
