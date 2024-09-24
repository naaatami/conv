#ifndef UNIT_H
#define UNIT_H

#include <string>
using namespace std;

struct Unit {
    string unitName;
    double conversionFactor;

    Unit() : unitName("undefined"), conversionFactor(1.0) {}

    Unit(string name, double conversion) :
    unitName(name), conversionFactor(conversion) {}

};


#endif
