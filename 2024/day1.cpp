#include "day1.hpp"

#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include "../CppUtil/util.hpp"

std::vector<int>
    leftVals,
    rightVals;

std::map<int,int> mP2 = {};


void day1::test() {
    util::qPrint(int(3) / 2);
}

void day1::main() {
    // test();
    day1::populateVecs();

    util::qPrint(day1::calcPartOne());
    util::qPrint(day1::calcPartTwo());
}

void day1::insertVal(int iVal, bool &rightVal) {
    if(rightVal) {
        if (mP2.contains(iVal)) {
            mP2[iVal] += 1;
        } else {
            mP2[iVal] = 1;
        }
    }
    std::vector<int>& vec = (rightVal) ? rightVals : leftVals;
    if(vec.empty()) {
        vec.push_back(iVal);
        return;
    }
    int iSize = vec.size();

    int i = iSize / 2;

    if(vec[i] > iVal) {
        do {
            i--;
            if(i < 0) {
                vec.emplace(vec.begin(),iVal);
                return;
            }
            if(iVal > vec[i]) {
                vec.emplace(vec.begin() + i + 1,iVal);
                return;
            }
        } while (vec[i] > iVal);
        vec.emplace(vec.begin() + i + 1,iVal);
        return;
    } else {
        do {
            i++;
            if(i > (iSize - 1)) {
                vec.push_back(iVal);
                return;
            }
            if(iVal < vec[i]) {
                vec.emplace(vec.begin()+i,iVal);
                return;
            }
        } while (vec[i] < iVal);
        vec.emplace(vec.begin()+i, iVal);
        return;
    }

}

void day1::populateVecs() {
    std::string sLine = "", sBuild = "";
    bool bLeftDone = false;
    MACRO_ReadFileByLine("inputs/24/d1", sLine, {
        sBuild.append(sLine);
        sBuild.push_back(' ');
    });

    leftVals.clear();
    rightVals.clear();
    bLeftDone = false;
    std::vector<std::string> vSplit = util::splitStringOnChar(sBuild, ' ');
    for(int i = vSplit.size() - 1; i > -1; i--) {
        insertVal(util::strToInt(vSplit[i]), bLeftDone);
        util::flip(bLeftDone);
    }

}

int day1::calcPartOne() {
    int iOutput = 0;
    if (leftVals.size() != rightVals.size()) {
        util::cPrint("red","They are the wrong size.", "Left:",leftVals.size(),"Right:",rightVals.size());
        throw;
    }

    for(int i = leftVals.size() - 1; i > -1; i--) {
        iOutput += abs(leftVals[i] - rightVals[i]);
    }

    return iOutput;
}

int day1::calcPartTwo() {
    int iOutput = 0;

    for(auto& lv : leftVals) {
        if(mP2.contains(lv)) {
            iOutput += (lv * mP2[lv]);
        }
    }

    return iOutput;
}
