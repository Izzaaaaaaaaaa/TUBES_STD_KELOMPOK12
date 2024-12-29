#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include "Edge.h"

using namespace std;

class Graph {
public:
    vector<Edge> edges;
    int numNodes;

    Graph(int n);
    void addEdge(int from, int to, double weight);
    void visualizeGraphASCII();
    void generateGraphvizDOT(const string &filename);
};

#endif
