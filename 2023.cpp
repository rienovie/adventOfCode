#include "2023.h"

namespace avc23 {

    const std::string numberList [9] = {
          "one",
          "two",
          "three",
          "four",
          "five",
          "six",
          "seven",
          "eight",
          "nine"
        };

    //if I want to optimize, can buildString once and compare with all
    //in the numberList of that length
    //will return -1 if not found
    int checkNumberString(std::string fullLine, int index) {
        std::string buildString;

        //loop for numberList; for each in numberList
        for (int numListIndex = 0; numListIndex < 9; numListIndex++) {
            buildString.clear();

            //loop to create name for comparison;
            for(int j = 0;j<numberList[numListIndex].length();j++){
                buildString.push_back(fullLine[index + j]);
            }

            if(buildString == numberList[numListIndex]) { return numListIndex; }

        }
        return -1;
    }


    void day1() {



        std::vector<std::string> input = util::getInput("../inputs/23_1_input");

        std::string firstDigit, secondDigit;
        bool firstDigitSet, secondDigitSet;
        int calibrateSum = 0; //output value
        int lineLength, numStrChk;
        std::string appendedString;

        //for each line
        for(std::string currentLine : input){

            lineLength = currentLine.length();
            appendedString.clear();
            firstDigitSet = false;
            secondDigitSet = false;

            //set digits
            //for each element in line
            for(int i = 0; i < lineLength;i++){

                if(!firstDigitSet) {
                    if(std::isdigit(currentLine[i])) {
                        firstDigit = currentLine[i];
                        firstDigitSet = true;
                    } else {
                        numStrChk = checkNumberString(currentLine,i);
                        if (numStrChk > -1){
                            firstDigit = std::to_string(numStrChk + 1);
                            firstDigitSet = true;
                        }
                    }
                }
                if(!secondDigitSet) {
                    if(std::isdigit(currentLine[(lineLength - 1) - i])){
                        secondDigit = currentLine[(lineLength - 1) - i];
                        secondDigitSet = true;
                    } else {
                        numStrChk = checkNumberString(currentLine,(lineLength - 1) - i);
                        if (numStrChk > -1){
                            secondDigit = std::to_string(numStrChk + 1);
                            secondDigitSet = true;
                        }
                    }
                }
                if(firstDigitSet && secondDigitSet){break;} //break when done

            }

            appendedString.append(firstDigit);
            appendedString.append(secondDigit);

            calibrateSum += std::stoi(appendedString);

            util::qPrint(appendedString);

        }

        //final output
        util::qPrint(calibrateSum);


    }


}
