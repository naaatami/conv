#include <string>
#include <map>
#include <iostream>
#include <vector>

#include "unit.h"
#include "mapping.h"

using namespace std;

double convert(double valueToConvert, Unit &initialUnit, Unit &endUnit);
int findMapping(string initialUnit, string endUnit);

int main(int argc, char *argv[]) {
    if (argc == 3 || argc == 4)
    {
        initializeUnitMaps();

        double initialValue = stod(argv[1]);
        string initialUnitString = argv[2];
        string endUnitString;

        if(argv[3] == string("to") && argv[4])
        {
            endUnitString = argv[4];
        } else {
            endUnitString = argv[3];
        }

        int mapIndex = findMapping(initialUnitString, endUnitString);
        if(mapIndex == -1)
        {
            cout << "ERROR: The two units given cannot be converted between.";
            return 0;
        }

        Unit initialUnit = unitList[mapIndex].at(initialUnitString);
        Unit endUnit = unitList[mapIndex].at(endUnitString);

        double endValue = convert(initialValue, initialUnit, endUnit);

        cout << initialValue << " " << initialUnit.unitName << " = " << endValue << " " << endUnit.unitName << "." << endl;

        return 0;
    } else {
        cout << "ERROR: Incorrect format." << endl;
    }
}

double convert(double valueToConvert, Unit &initialUnit, Unit &endUnit){
    double endValue = valueToConvert * initialUnit.conversionFactor;
    return endValue / endUnit.conversionFactor;
}

int findMapping(string initialUnit, string endUnit)
{
    bool initialAndEndMatch = false;
    for(int i = 0; i < unitList.size(); i++)
    {
        try
        {
            unitList[i].at(initialUnit);
        }

        catch(const std::out_of_range& ex)
        {
            continue;
        }

        try
        {
            unitList[i].at(endUnit);
        }

        catch(const std::out_of_range& ex)
        {
            continue;
        }

        initialAndEndMatch = true;
        return i;
    }
    //better error handling needed here
    return -1;
}

