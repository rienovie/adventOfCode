#pragma once

#include "../util.h"
#include <string>
#include <vector>

struct boatRace {
    long long time = 0, distance = 0;
};

void day6();
std::vector<boatRace> getBoatRaces();
int getRaceWins(boatRace race);
boatRace getPart2Race();
