#include "2015.h"

namespace avc15 {

    //Challenge is ( means +1 and ) mean -1
    //Second for first index in basement

    void day1 () {

        std::string input;

        for(std::string line : util::getInput("../old/inputs/2015_1_input")) {
            input.append(line);
        }

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


    //Challenge is calc total area of wrapping paper needed
    //2*l*w + 2*w*h + 2*h*l plus add the smallest side

    void day2(){
        struct boxDims { int width, height, length;};

        int finalOutput;
        std::vector<std::string> lines = util::getInput("../old/inputs/2015_2_input");
        //dims are 0 width, 1 height, 2 length
        int currentDim;
        std::string tempStr;

        boxDims currentBox;

        //for each line (box)
        for(std::string line : lines){
            currentDim = 0;
            tempStr.clear();

            //set the dimentions of the box
            for(char element : line){
                if(element == 'x') {
                    switch (currentDim) {
                        case 0:
                            currentBox.width = std::stoi(tempStr);
                            break;
                        case 1:
                            currentBox.height = std::stoi(tempStr);
                            break;
                        case 2:
                            currentBox.length = std::stoi(tempStr);
                            break;
                    }
                    tempStr.clear();
                    currentDim++;
                }
                else tempStr.append("%c",element);
            }



        }


    }

}
