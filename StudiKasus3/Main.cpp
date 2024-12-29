#include <iostream>
#include "Graph.h"
#include "TravelingSalesman.h"
#include "Edge.h"
#include "Edge.cpp"
#include "Graph.cpp"
#include "TravelingSalesman.cpp"

using namespace std;

int main() {
    Graph g(5);

    g.addEdge(1, 4, 200);
    g.addEdge(1, 3, 800);
    g.addEdge(2, 1, 160);
    g.addEdge(2, 4, 900);
    g.addEdge(3, 2, 200);
    g.addEdge(3, 4, 880);
    g.addEdge(4, 5, 123);
    g.addEdge(5, 1, 678);

    g.visualizeGraphASCII();

    // Generate DOT file for Graphviz
    string dotFile = "graph.dot";
    g.generateGraphvizDOT(dotFile);

    // Call Graphviz to generate PNG
    string outputFile = "graph.png";
    string command = "dot -Tpng " + dotFile + " -o " + outputFile;
    system(command.c_str());
    cout << "Grafik telah divisualisasikan ke file: " << outputFile << endl;

    int startNode = 1;
    auto [optimalRoute, minimalCost] = TravelingSalesman::solve(g, startNode);

    cout << "\n===================================\n";
    cout << "        Hasil Optimasi Rute        \n";
    cout << "===================================\n";
    cout << "Rute Optimal: ";
    for (int node : optimalRoute) {
        cout << node << " ";
    }
    cout << "\nBiaya Minimal: " << minimalCost << "\n";

    cout << "\nDetail Rute Optimal:\n";
    for (size_t i = 0; i < optimalRoute.size() - 1; ++i) {
        cout << "  Node " << optimalRoute[i] << " -> Node " << optimalRoute[i + 1] << "\n";
    }

    return 0;
}
