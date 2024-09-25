#ifndef MAPPING_H
#define MAPPING_H

#include <map>
#include <string>
#include <vector>
#include "unit.h"

extern std::vector<std::map<std::string, Unit>> unitList;

void initializeUnitMaps();

#endif // MAPPING_H
