#include "Edge.h"
#include <iostream>

using namespace std;
void Edge::printEdge() const {
    cout << "Edge from " << from << " to " << to << " with weight " << weight << endl;
}
