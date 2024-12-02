#include "day6.h"

std::vector<std::string> inputD6 = util::getInput("../inputs/23_6_input");



void day6(){
    std::vector<boatRace> racesInput = getBoatRaces();
    std::vector<int> raceWins;
    int part1Out = 0;

    for(boatRace race : racesInput){
        raceWins.push_back(getRaceWins(race));
    }

    for(int wins : raceWins){
        if(part1Out == 0) { part1Out = wins; }
        else part1Out *= wins;
    }

    util::qPrint("Part 1:",part1Out);

    util::qPrint(getRaceWins(getPart2Race()));





}

std::vector<boatRace> getBoatRaces(){
    std::vector<boatRace> output;
    std::string buildString;
    std::vector<int> lineValues;
    bool distanceLine;

    //for each line
    for(std::string line : inputD6){
        buildString.clear();
        lineValues.clear();
        distanceLine = (line[0]=='D');

        //for chars in line
        for(int i = 9;i<line.length();i++){
            if(line[i] == ' ' && buildString.length()>=1){
                lineValues.push_back(util::strToInt(buildString));
                buildString.clear();
            } else
                if(std::isdigit(line[i])) {
                buildString.push_back(line[i]);
            }
        }
        //add last element
        lineValues.push_back(util::strToInt(buildString));


        //for each value
        for(int i = 0;i<lineValues.size();i++ ){
            if(distanceLine){
                output[i].distance = lineValues[i];
            } else {
                boatRace newRace;
                newRace.time = lineValues[i];
                output.push_back(newRace);
            }
        }

    }

    return output;
}

int getRaceWins(boatRace race) {
    long long start = race.time / 2;
    bool win = true; //sets to false when
    int output = 0;

    //is odd
    if(race.time % 2 != 0){
        for (int i = 0;win;i++){
            if((start - i)*(start+i+1) > race.distance) {output += 2;}
            else win = false;
        }
    } else {
        //I assume there won't be invalid games but I account for them
        if((start * start) > race.distance) { output++; }
        for(int i = 1;win;i++){
            if((start - i)*(start+i) > race.distance) {output += 2;}
            else win = false;
        }
    }

    return output;
}


boatRace getPart2Race(){
    boatRace output;

    std::string buildString;
    bool distanceLine;

    for(std::string line : inputD6){
        buildString.clear();
        distanceLine = (line[0]=='D');

        for(int i = 9;i<line.length();i++){
            if(std::isdigit(line[i])) { buildString.push_back(line[i]); }
        }

        if(distanceLine) { output.distance = std::stoull(buildString); }
        else output.time = std::stoll(buildString);

    }

    return output;

}
