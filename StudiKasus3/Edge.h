#ifndef EDGE_H
#define EDGE_H

#include <iostream>

struct Edge {
    int from, to;
    double weight;

    Edge(int from, int to, double weight)
        : from(from), to(to), weight(weight) {}

    void printEdge() const; 
};

#endif 
