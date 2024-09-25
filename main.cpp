#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "unit.h"
#include "mapping.h"

using namespace std;

double convert(double valueToConvert, Unit &initialUnit, Unit &endUnit);
bool findMapping(int &mapIndex, string initialUnit, string endUnit);

int main(int argc, char *argv[]) {
    // checking for correct amount of arguments entered
    if (argc == 3 || argc == 4) {
        initializeUnitMaps();

        double initialValue = stod(argv[1]);
        string initialUnitString = argv[2];
        string endUnitString;

        if(argv[3] == string("to") && argv[4]) {
            endUnitString = argv[4];
        }

        else {
            endUnitString = argv[3];
        }

        // checks that units can be converted to and from before converting
        int mapIndex = 0;
        bool mappingFound = findMapping(mapIndex, initialUnitString, endUnitString);

        if(!mappingFound) {
            cout << "ERROR: The units provided cannot be converted between." << endl;
            return 0;
        }

        Unit initialUnit = unitList[mapIndex].at(initialUnitString);
        Unit endUnit = unitList[mapIndex].at(endUnitString);
        double endValue = convert(initialValue, initialUnit, endUnit);

        // outputs final result
        cout << initialValue << " " << initialUnit.unitName << " = " << endValue << " " << endUnit.unitName << "." << endl;
        return 0;

    // not enough arguments - provide correct usage
    } else {
        cout << "ERROR: Incorrect format" << endl;
        cout << "Correct format: conv <value> <initial_unit> <end_unit>" << endl;
        cout << "Example usage: conv 40 km m" << endl;
    }
}


// converts from the initialUnit to endUnit
double convert(double valueToConvert, Unit &initialUnit, Unit &endUnit) {
    double endValue = valueToConvert * initialUnit.conversionFactor;
    return endValue / endUnit.conversionFactor;
}

// finds the correct map index for two given units
// returns false if nothing can be found
bool findMapping(int &mapIndex, string initialUnit, string endUnit) {
    bool initialAndEndMatch = false;
    while(mapIndex < unitList.size() && initialAndEndMatch == false) {
        try {
            unitList[mapIndex].at(initialUnit);
            unitList[mapIndex].at(endUnit);
        }
        catch(const std::out_of_range& ex) {
            mapIndex++;
            continue; // try to get rid of this
        }
        initialAndEndMatch = true;
    }
    return initialAndEndMatch;
}

