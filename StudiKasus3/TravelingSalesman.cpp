#include "TravelingSalesman.h"
#include <algorithm>
#include <limits>

using namespace std;

    pair<vector<int>, double> TravelingSalesman::solve(const Graph &graph, int startNode) {
    vector<int> nodes;
    for (int i = 1; i <= graph.numNodes; i++) {
        if (i != startNode) nodes.push_back(i);
    }

    vector<int> bestRoute;
    double minCost = numeric_limits<double>::max();

    do {
        double cost = 0.0;
        int currentNode = startNode;

        for (int nextNode : nodes) {
            bool found = false;
            for (const auto &edge : graph.edges) {
                if ((edge.from == currentNode && edge.to == nextNode) ||
                    (edge.from == nextNode && edge.to == currentNode)) {
                    cost += edge.weight;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cost = numeric_limits<double>::max();
                break;
            }
            currentNode = nextNode;
        }

        for (const auto &edge : graph.edges) {
            if ((edge.from == currentNode && edge.to == startNode) ||
                (edge.from == startNode && edge.to == currentNode)) {
                cost += edge.weight;
                break;
            }
        }

        if (cost < minCost) {
            minCost = cost;
            bestRoute = nodes;
        }
    } while (next_permutation(nodes.begin(), nodes.end()));

    bestRoute.insert(bestRoute.begin(), startNode);
    bestRoute.push_back(startNode);

    return {bestRoute, minCost};
}
