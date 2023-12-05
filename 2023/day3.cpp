#include "day3.h"

std::vector<std::string> inputD3 = util::getInput("../inputs/23_3_input");

//scope feels bad, but am struggling today
char charToCheck;

int2D surroundingLocations[8] {
{-1,-1},
{-1,0},
{-1,1},
{0,-1},
{0,1},
{1,-1},
{1,0},
{1,1}
};

void foundNumber::setValues(int2D start, int val){
    startIndex = start;
    value = val;
}

std::vector<foundNumber> foundPartNumbers;
std::array<foundNumber, 2> foundGears;


void day3(){

    //0 = lineNumber ; 1 = char index
    std::vector<int2D> symbolLocations;


    int partNumberSum = 0;
    int gearRatioSum = 0;

    //for each line of input
    for (int lineIndex = 0; lineIndex<inputD3.size(); lineIndex++){
        std::string line = inputD3[lineIndex];

        //first pass to find symbol locations
        for (int lineElement = 0; lineElement<line.length();lineElement++){

            char currentChar = getElement({lineIndex,lineElement});

            //exclude numbers and period
            if(currentChar == '.' || std::isdigit(currentChar)) { continue; }
            symbolLocations.push_back({lineIndex,lineElement});

        }
    }

    //for each symbol found
    for(int2D symbolLoc : symbolLocations){

        //loop thru all surrounding locations
        for(int surroundingIndex = 0;surroundingIndex<8;surroundingIndex++) {

            int2D locToCheck = addInt2D(symbolLoc, surroundingLocations[surroundingIndex]);
            charToCheck = getElement(locToCheck);
            if(std::isdigit(charToCheck)) { addToParts(getFullNumber(locToCheck)); }

        }

    }

    //for each part Number sum up
    for(foundNumber part : foundPartNumbers){
        partNumberSum += part.value;
    }

    util::qPrint("Part Number Sum:",partNumberSum);

    //part 2
    //loop thru all symbols
    for(int2D sym : symbolLocations){
        if(getElement(sym) == '*'){ //specific gear element
            foundGears[0].setValues({0,0},0);
            foundGears[1].setValues({0,0},0);

            //loop thru surrounding
            for(int surroundingIndex = 0; surroundingIndex<8; surroundingIndex++) {
                int2D locToCheck = addInt2D(sym, surroundingLocations[surroundingIndex]);
                charToCheck = getElement(locToCheck);

                //doesn't exclude more than two but passes and today's been rough
                if(std::isdigit(charToCheck)){
                    if(addToGears(getFullNumber(locToCheck))){
                        if(foundGears[0].value > 0 && foundGears[1].value > 0){
                            gearRatioSum += (foundGears[0].value * foundGears[1].value);
                            break;
                        }
                    }
                }
            }
        }
    }

    util::qPrint("Gear Ratio Sum: ", gearRatioSum);

}

char getElement(int2D loc) {
    if(loc.x > inputD3.size() || loc.x < 0 || loc.y > inputD3[loc.x].length() || loc.y < 0) {return '.';}
    return inputD3[loc.x][loc.y];
}

foundNumber getFullNumber(int2D initialLocation) {
    int2D leftNumberBounds;
    char curChar = getElement(initialLocation);
    std::string buildStr;
    buildStr.push_back(curChar);
    int indexOffset = 0;

    //leftward could make this better but not today
    while(std::isdigit(curChar)){
        indexOffset += 1;
        curChar = getElement({initialLocation.x, (initialLocation.y - indexOffset)});
        if(std::isdigit(curChar)) {
            buildStr.insert(buildStr.begin(),curChar);
        }
    }

    leftNumberBounds = {initialLocation.x,(initialLocation.y - indexOffset)};
    curChar = getElement(initialLocation);
    indexOffset = 0;

    //rightward could make this better but not today
    while(std::isdigit(curChar)){
        indexOffset += 1;
        curChar = getElement({initialLocation.x, (initialLocation.y + indexOffset)});
        if(std::isdigit(curChar)) {
            buildStr.push_back(curChar);
        }
    }

    foundNumber output = foundNumber();
    output.setValues(leftNumberBounds,util::strToInt(buildStr));

    return output;

}

int2D addInt2D(int2D a, int2D b){
    return int2D {a.x + b.x , a.y + b.y};
}

void addToParts(foundNumber toAdd){
    //loop thru found list
    for(foundNumber element : foundPartNumbers){
        if(element.startIndex.x == toAdd.startIndex.x && element.startIndex.y == toAdd.startIndex.y) {return;}
    }
    foundPartNumbers.push_back(toAdd);
    //util::qPrint(toAdd.value);
}

//returns if gear is valid
bool addToGears(foundNumber toAdd){
    //loop thru found list
    for(foundNumber element : foundGears){
        if(element.startIndex.x == toAdd.startIndex.x && element.startIndex.y == toAdd.startIndex.y) { return true; }
    }
    if(foundGears[0].value == 0) {foundGears[0] = toAdd; return true;}
    if(foundGears[1].value == 0) {foundGears[1] = toAdd; return true;}
    return false;
}
