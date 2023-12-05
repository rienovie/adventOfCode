#pragma once

#include "../util.h"
#include <array>

void day4();
std::vector<int> getValues(std::string line, bool winningValues);
std::string getValuesAsString(std::vector<int> values);
int determineFinalCardCount();
