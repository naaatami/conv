#include "mapping.h"
#include "unit.h"
#include <iostream>

using namespace std;

vector<map<string, Unit>> unitList;

void initializeUnitMaps()
{
    map<string, Unit> lengthUnits =
    {
        {"millimeters", Unit("millimeters", 0.0001)},
        {"millimeter", Unit("millimeters", 0.0001)},
        {"mm", Unit("millimeters", 0.0001)},

        {"centimeter", Unit("centimeters", 0.01)},
        {"centimeters", Unit("centimeters", 0.01)},
        {"cm", Unit("centimeters", 0.01)},

        {"meter", Unit("meters", 1.0)},
        {"meters", Unit("meters", 1.0)},
        {"m", Unit("meters", 1.0)},

        {"kilometer", Unit("kilometers", 1000.0)},
        {"kilometers", Unit("kilometers", 1000.0)},
        {"km", Unit("kilometers", 1000.0)},

        {"in", Unit("inches", 0.0254)},
        {"inches", Unit("inches", 0.0254)},
        {"inch", Unit("inches", 0.0254)},

        {"ft", Unit("feet", 0.3048)},
        {"foot", Unit("feet", 0.3048)},
        {"feet", Unit("feet", 0.3048)},

        {"yard", Unit("yards", 0.9144)},
        {"yards", Unit("yards", 0.9144)},
        {"yd", Unit("yards", 0.9144)},

        {"mi", Unit("miles", 1609.344)},
        {"mile", Unit("miles", 1609.344)},
        {"miles", Unit("miles", 1609.344)}
    };

    map<string, Unit> timeUnits =
    {
        {"second", Unit("seconds", 0.0002777777777777778)},
        {"seconds", Unit("seconds", 0.0002777777777777778)},
        {"sec", Unit("seconds", 0.0002777777777777778)},
        {"s", Unit("seconds", 0.0002777777777777778)},

        {"m", Unit("minutes", 0.01666666666666667)},
        {"min", Unit("minutes", 0.01666666666666667)},
        {"minutes", Unit("minutes", 0.01666666666666667)},
        {"minute", Unit("minutes", 0.01666666666666667)},

        {"hour", Unit("hours", 1.0)},
        {"hours", Unit("hours", 1.0)},
        {"hr", Unit("hours", 1.0)},

        {"day", Unit("days", 24.0)},
        {"days", Unit("days", 24.0)}
    };

    map<string, Unit> weightUnits =
    {
        {"gram", Unit("grams", 1.0)},
        {"grams", Unit("grams", 1.0)},
        {"g", Unit("grams", 1.0)},

        {"kilogram", Unit("kilograms", 1000)},
        {"kilograms", Unit("kilograms", 1000)},
        {"kg", Unit("kilograms", 1000)},

        {"pound", Unit("pounds", 453.59237)},
        {"lb", Unit("pounds", 453.59237)},
        {"lbs", Unit("pounds", 453.59237)},
        {"pounds", Unit("pounds", 453.59237)},

        {"ounce", Unit("ounces", 28.3495231)},
        {"oz", Unit("ounces", 28.3495231)},
        {"ounces", Unit("ounces", 28.3495231)}
    };

    unitList.push_back(lengthUnits);
    unitList.push_back(timeUnits);
    unitList.push_back(weightUnits);
}






