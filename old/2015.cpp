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
    //Second star is sum of two smallest sides x2 plus volume of box (w*h*l)

    void day2(){
        struct boxDims {
            int width, height, length;
            void clearValues(){
                width = 0;
                height = 0;
                length = 0;
            }
            int getValueByIndex(int index){
                switch (index){
                    case 0:
                        return this->width;
                    case 1:
                        return this->height;
                    case 2:
                        return this->length;
                    default:
                        std::cout << "valueByIndex not valid\n";
                        return 0;
                }
            }
            int wrapSize(){
                int output = 0;
                int largest = 0;
                for(int i = 0;i<3;i++){
                    if(getValueByIndex(i) > getValueByIndex(largest)) {largest = i;}
                }
                for(int i = 0;i<3;i++){
                    if(i == largest) continue;
                    output += (getValueByIndex(i) * 2);
                }

                return output;
            }
        };

        int wrappingPaper = 0;
        std::vector<std::string> lines = util::getInput("../old/inputs/2015_2_input");
        int currentDim; //dims are 0 width, 1 height, 2 length
        std::string tempStr;
        boxDims currentBox;
        boxDims currentBoxArea;
        int ribbon = 0;

        //for each line (box)
        for(std::string line : lines){
            currentBox.clearValues();
            currentBoxArea.clearValues();
            currentDim = 0; //used for box dims and to determine smallest value
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
                        default:
                            util::qPrint("Error on line dimention set");
                            break;
                    }

                    tempStr.clear();
                    currentDim++;
                }
                else tempStr.push_back(element);
            }

            currentBox.length = std::stoi(tempStr);

            //check if not valid
            if(currentBox.width <= 0) {util::qPrint("Line invalid"); continue;}

            currentDim = 0; //will be set to which is the lowest (smallest)
            //l*w , w*h , h*l

            currentBoxArea.width = (currentBox.width * currentBox.length);

            currentBoxArea.height = (currentBox.height * currentBox.width);
            if(currentBoxArea.height < currentBoxArea.width) {currentDim = 1;}
            currentBoxArea.length = (currentBox.length * currentBox.height);
            if(currentBoxArea.length < currentBoxArea.getValueByIndex(currentDim)) {currentDim = 2;}

            //add to totals
            wrappingPaper += (currentBoxArea.width * 2);
            wrappingPaper += (currentBoxArea.height * 2);
            wrappingPaper += (currentBoxArea.length * 2);
            wrappingPaper += (currentBoxArea.getValueByIndex(currentDim));

            ribbon += (currentBox.width * currentBox.height * currentBox.length); //bow
            ribbon += currentBox.wrapSize(); //ribbon wrap


        } //end of individual box

        util::qPrint(wrappingPaper);
        util::qPrint("Wrapping Paper");
        util::qPrint(ribbon);
        util::qPrint("Ribbon");


    }

}
