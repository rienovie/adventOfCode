#include "2015.h"

namespace avc15 {

    //Challenge is ( means +1 and ) mean -1
    //Second for first index in basement

    void day1 () {

        std::ifstream file;
        file.open("../old/inputs/2015_1_input.txt");

        std::string input;

        getline(file, input);
        file.close();

        int result = 0;
        bool onceCheck = false;
        int indexBasement = 0;

        for(int index = 1; char i : input){
            if (i == '(') {result++;}
            if (i == ')') {result--;}
            if (result < 0 && !onceCheck) {
                indexBasement = index;
                onceCheck = true;
            }
            index++;
        }

        std::cout << "Santa is on floor " << result << std::endl;
        std::cout << "Index of first basement " << indexBasement;

    }

}
