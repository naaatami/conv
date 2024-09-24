#include <string>
#include <map>
#include <iostream>

#include "Unit.h"

using namespace std;

double convert(double valueToConvert, Unit &initialUnit, Unit &endUnit);

int main(int argc, char *argv[]) {

    if (argc == 1)
    {
        cout << "ERROR: No arguments given.\n";
        return 0;
    }

    else if (argc == 2 || argc == 3) {
        //TODO: if only three arguments given, can list all unit conversions
        cout << "ERROR: No units given.\n";
        return 0;
    }

    if (argc > 5)
    {
        cout << "Too many arguments found - extra ones have been ignored.";
    }

    map<string, Unit> lengthUnits =
    {
        {"meter", Unit("meters", 1.0)},
        {"meters", Unit("meters", 1.0)},
        {"m", Unit("meters", 1.0)},
        {"kilometer", Unit("kilometers", 1000.0)},
        {"kilometers", Unit("kilometers", 1000.0)},
        {"km", Unit("kilometers", 1000.0)},
        {"ft", Unit("feet", 0.3048)},
        {"foot", Unit("feet", 0.3048)},
        {"feet", Unit("feet", 0.3048)}
    };

    // map<string, UnitFormula> temperatureUnits =
    // {
    //     {"fahrenheit", Unit("celsius",
    //     {"f",
    // };


    double initialValue = stod(argv[1]);
    Unit initialUnit = lengthUnits.at(argv[2]);
    Unit endUnit;
    if(argv[3] == "to" || argv[4])
    {
        endUnit = lengthUnits.at(argv[4]);
    } else {
        endUnit = lengthUnits.at(argv[3]);
    }

    cout << initialValue << endl;
    cout << initialUnit.unitName << endl;
    cout << endUnit.unitName << endl;

    double endValue = convert(initialValue, initialUnit, endUnit);

    cout << initialValue << " " << initialUnit.unitName << " is equivalent to " << endValue << " " << endUnit.unitName << "." << endl;

    return 0;
}

double convert(double valueToConvert, Unit &initialUnit, Unit &endUnit){
    double endValue = valueToConvert * initialUnit.conversionFactor;
    return endValue / endUnit.conversionFactor;
}

