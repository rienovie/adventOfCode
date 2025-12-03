#include "day1.hpp"
#include "../CppUtil/util.hpp"
#include <string>
#include <vector>

void day1::main() {
    std::vector<std::string> sInput = util::fileToVector("inputs/25/d1");

    bool bRight = false, bAlreadyIncremented = false;
    int iCurLocation = 50, iValue = 0, iOutput = 0;
    std::string sDebug;
    for(auto& sLine : sInput) {
        sDebug.clear();
        bRight = (sLine[0] == 'R' || sLine[0] == 'r');
        iValue = util::strToInt(sLine.substr(1));
        sDebug += std::to_string(iCurLocation) + " CurLoc prior / ";
        iCurLocation = (bRight ? iCurLocation + iValue : iCurLocation - iValue);
        sDebug += std::to_string(iCurLocation) + " CurLoc after / ";
        while(iCurLocation < 0) {
            iCurLocation += 100;
            iOutput++;
            // bAlreadyIncremented = true;
        }
        while(iCurLocation > 99) {
            iCurLocation -= 100;
            iOutput++;
            // bAlreadyIncremented = true;
        }
        if(iCurLocation == 0 && !bAlreadyIncremented) {
            iOutput++;
        }

        sDebug += std::to_string(iValue) + " Value / ";
        sDebug += std::to_string(bRight) + " Right / ";
        sDebug += std::to_string(iCurLocation) + " CurLoc final / ";
        sDebug += std::to_string(iOutput) + " Output / ";
        sDebug += sLine;
        util::qPrint(sDebug);
    }

    util::qPrint(iOutput);
}
