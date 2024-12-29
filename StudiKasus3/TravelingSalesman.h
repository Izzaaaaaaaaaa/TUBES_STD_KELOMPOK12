#ifndef TRAVELINGSALESMAN_H
#define TRAVELINGSALESMAN_H

#include <vector>
#include <utility>
#include "Graph.h"

using namespace std;

class TravelingSalesman {
public:
    static pair<vector<int>, double> solve(const Graph &graph, int startNode);
};

#endif
