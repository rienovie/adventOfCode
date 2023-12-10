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

}
