#include "day2.h"



class day2Game {

public:

    enum gameColors {red,green,blue};
    int gameNumber = 0;
    bool gameValid = true;

    int getValue(gameColors color){
        switch (color) {
            case red:
                return red_p;
            case green:
                return green_p;
            case blue:
                return blue_p;
        }
    }

    int getPowerOfHighest() {
        return (highestRed_p * highestGreen_p * highestBlue_p);
    }

    //returns if in bounds
    bool setValue(gameColors color,int valueToSet){
        switch (color){
            case red:
                if(valueToSet > highestRed_p) { highestRed_p = valueToSet; }
                if(valueToSet > redMax_p) {
                    red_p = valueToSet;
                    return false;
                }
                else red_p = valueToSet;
                return true;

            case green:
                if(valueToSet > highestGreen_p) { highestGreen_p = valueToSet; }
                if(valueToSet > greenMax_p) {
                    green_p = valueToSet;
                    return false;
                }
                else green_p = valueToSet;
                return true;

            case blue:
                if(valueToSet > highestBlue_p) { highestBlue_p = valueToSet; }
                if(valueToSet > blueMax_p) {
                    blue_p = valueToSet;
                    return false;
                }
                else blue_p = valueToSet;
                return true;

            default:
                util::qPrint("Error in setValue on class day2Game");
                return false;
        }
    }

    void resetGame(){
        highestBlue_p = 0;
        highestGreen_p = 0;
        highestRed_p = 0;
        gameNumber = 0;
        gameValid = true;
        red_p = 0;
        green_p = 0;
        blue_p = 0;
    }


private:
    int red_p = 0, green_p = 0, blue_p = 0;
    int redMax_p = 12;
    int greenMax_p = 13;
    int blueMax_p = 14;
    int highestRed_p, highestGreen_p, highestBlue_p;

};

void day2(){

    std::vector<std::string> input = util::getInput("../inputs/23_2_input");

    int validGameSum = 0;
    int lastEndIndex;
    int powerSum = 0;
    std::string buildNumString;

    day2Game* currentGame = new day2Game;

    //for each line
    for(std::string line : input){

        currentGame->resetGame();
        buildNumString.clear();

        //find game number and set
        for(int i = 5;line[i] != ':';i++) {
            buildNumString.push_back(line[i]);
            lastEndIndex = i;
        }
        currentGame->gameNumber = std::stoi(buildNumString);
        buildNumString.clear();

        for(int i = lastEndIndex + 3;i<line.length();i++){

            if(line[i] == ' '){

                if(std::isdigit(line[i-1])) {

                    switch (line[i+1]){

                        case 'r':
                            if(!currentGame->setValue(currentGame->red,std::stoi(buildNumString))) {
                                currentGame->gameValid = false;
                            }
                            break;

                        case 'g':
                            if(!currentGame->setValue(currentGame->green,std::stoi(buildNumString))) {
                                currentGame->gameValid = false;
                            }
                            break;

                        case 'b':
                            if(!currentGame->setValue(currentGame->blue,std::stoi(buildNumString))) {
                                currentGame->gameValid = false;
                            }
                            break;
                    }

                    buildNumString.clear();

                }

            } else if(std::isdigit(line[i])) { buildNumString.push_back(line[i]); }

            //with part one would end if line was invalid but part two wanted all games even invalid
            //if(!currentGame->gameValid) {break;}

        }

        if(currentGame->gameValid){
            validGameSum += currentGame->gameNumber;

        }

        powerSum += currentGame->getPowerOfHighest();

    }

    util::qPrint(validGameSum);
    util::qPrint("Game Sum");
    util::qPrint(powerSum);
    util::qPrint("Power Sum");

    delete currentGame;
}

