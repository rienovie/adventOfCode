#include "day4.h"

std::vector<std::string> inputD4 = util::getInput("../inputs/23_4_input");

//fixed size array
int matches[196], incrementAmounts[196];

//input values are on the same indexes for each line so I will be quick
//and just get by specific indexes instead of iterating
void day4(){

    std::string currentLine;
    std::vector<int> winValues, yourValues;
    int scratchCardTotalPoints = 0, currentScratchCardPoints;


    //each line (card)
    for(int i = 0;i<inputD4.size()-1;i++){
        currentLine = inputD4[i];
        winValues = getValues(currentLine,true);
        yourValues = getValues(currentLine,false);
        currentScratchCardPoints = 0;

        for(int yourValue : yourValues){
            for(int winValue : winValues){
                if(yourValue == winValue){
                    if(currentScratchCardPoints == 0) {
                        currentScratchCardPoints = 1;
                        matches[i] = 1;
                    } else {
                        currentScratchCardPoints *= 2;
                        matches[i] += 1;
                    }
                    continue;
                }
            }
        }

        scratchCardTotalPoints += currentScratchCardPoints;
    }

    util::qPrint(scratchCardTotalPoints);
    util::qPrint(determineFinalCardCount());

}


std::vector<int> getValues(std::string line, bool winningValues){
    //starts at index 10-11 each is two and ends at index 37-38
    std::vector<int> output;
    int loopCount, indexOffset;
    if(winningValues){
        loopCount = 10;
        indexOffset = 10;
    } else {
        loopCount = 25;
        indexOffset = 42;
    }

    int currentIndex = 0;
    std::string buildString;
    for(int i = 0;i<loopCount;i++){
        buildString.clear();
        currentIndex = (i*3) + indexOffset;
        buildString.push_back(line[currentIndex]);
        buildString.push_back(line[currentIndex + 1]);
        output.push_back(util::strToInt(buildString));
    }

    return output;
}

//testing
std::string getValuesAsString(std::vector<int> values){
    std::string buildString;
    for(int i : values){
        buildString.append(std::to_string(i));
        buildString.push_back(' ');
    }
    return buildString;
}

int determineFinalCardCount() {
    int output = 0;

    for(int i = 0;i<196;i++){
        //each card once
        for(int j = 0;j<incrementAmounts[i]+1;j++){
            output += 1;
            for(int j = 0;j<matches[i];j++){
                incrementAmounts[i+j+1] += 1;
            }
        }
    }

    return output;
}

