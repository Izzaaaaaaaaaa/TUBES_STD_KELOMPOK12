#ifndef OPTIMASIRUTE_H
#define OPTIMASIRUTE_H

#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include "Rute.h"
using namespace std;

class OptimasiRute {
public:
    pair<vector<int>, int> travelingSalesman(Rute &rute, int start, int jumlahNode);
};

#endif
