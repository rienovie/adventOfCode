#include "day2.hpp"
#include "../CppUtil/util.hpp"
#include <string>
#include <vector>

std::vector<std::string> vInputLines;
std::vector<std::vector<int>> vValidLines;

void day2::main() {
    populateLines();
    calcPartOne();
}

void day2::populateLines() {
    std::string sLine = "", sBuild = "";
    std::vector<int> vCurVals;
    int iCur, iDiff;
    bool bDetermined = false, bIncrease = false;
    MACRO_ReadFileByLine("inputs/24/d2", sLine, {
        bDetermined = false;
        bIncrease = false;
        sBuild.clear();
        vCurVals.clear();
        vInputLines.push_back(sLine);

        for(char& c : sLine) {
            if(c == ' ') {
                iCur = util::strToInt(sBuild);
                if(bDetermined) {
                    iDiff = iCur - vCurVals.back();
                    if(((bIncrease && iDiff > 0) || ((!bIncrease) && iDiff < 0))
                    && (abs(iDiff) < 1 || abs(iDiff) > 3)) {
                        sBuild.clear();
                        break;
                    }
                    vCurVals.push_back(iCur);
                    sBuild.clear();
                } else if(vCurVals.size() > 0) {
                    iDiff = iCur - vCurVals[0];
                    //diff check
                    if(abs(iDiff) < 1 || abs(iDiff) > 3) {
                        sBuild.clear();
                        break;
                    }
                    bIncrease = (iDiff > 0);
                    bDetermined = true;
                    vCurVals.push_back(iCur);
                    sBuild.clear();
                } else {
                    vCurVals.push_back(iCur);
                    sBuild.clear();
                    util::qPrint(vInputLines.size());
                }
            } else {
                sBuild.push_back(c);
            }
        }
        if(sBuild.length() < 1) {
            util::qPrint("Rejected line:",vInputLines.size());
            continue; // line rejected
        }

        iCur = util::strToInt(sBuild);
        iDiff = iCur - vCurVals.back();

        //if reject
        if(((bIncrease && iDiff > 0) || (!bIncrease && iDiff < 0))
        && (abs(iDiff) < 1 || abs(iDiff) > 3)) {
            util::qPrint("Rejected line:",vInputLines.size());
            continue;
        }

        vCurVals.push_back(iCur);
        vValidLines.push_back(vCurVals);
    });
}

void day2::calcPartOne() {
    util::qPrint(vValidLines.size());
}
