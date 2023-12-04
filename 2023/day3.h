#pragma once

#include "../util.h"
#include <array>

struct int2D { int x, y; };

struct foundNumber {
    int2D startIndex;
    int value;

    void setValues(int2D start, int val);
};

void day3();
char getElement(int2D loc);
foundNumber getFullNumber(int2D initialLocation);
int2D addInt2D(int2D a, int2D b);
void addToParts(foundNumber toAdd);
bool addToGears(foundNumber toAdd);
