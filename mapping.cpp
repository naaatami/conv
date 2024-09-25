#include "mapping.h"
#include "unit.h"
#include <iostream>


std::vector<std::map<std::string, Unit>> unitList;

void initializeUnitMaps()
{
    std::map<std::string, Unit> lengthUnits =
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

    std::map<std::string, Unit> timeUnits =
    {
        {"hour", Unit("hours", 1.0)},
        {"hours", Unit("hours", 1.0)},
        {"hr", Unit("hours", 1.0)},
        {"min", Unit("minutes", 60.0)},
        {"minutes", Unit("minutes", 60.0)},
        {"minute", Unit("minutes", 60.0)},
        {"day", Unit("days", 0.0417)},
        {"days", Unit("days", 0.0417)},
        {"second", Unit("seconds", 0.00027778)},
        {"seconds", Unit("seconds", 0.00027778)},
        {"sec", Unit("seconds", 0.00027778)}
    };

    std::map<std::string, Unit> weightUnits =
    {
        {"gram", Unit("grams", 1.0)},
        {"grams", Unit("grams", 1.0)},
        {"g", Unit("grams", 1.0)},
        {"kilogram", Unit("kilograms", 0.001)},
        {"kilograms", Unit("kilograms", 0.001)},
        {"kg", Unit("kilograms", 0.001)}
    };

    unitList.push_back(lengthUnits);
    unitList.push_back(timeUnits);
    unitList.push_back(weightUnits);
}






