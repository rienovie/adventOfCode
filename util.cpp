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


}
