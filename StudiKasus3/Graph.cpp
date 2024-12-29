#include "Graph.h"
#include <fstream>
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

Graph::Graph(int n) : numNodes(n) {}

void Graph::addEdge(int from, int to, double weight) {
    edges.push_back({from, to, weight});
}

void Graph::visualizeGraphASCII() {
    cout << "===========================\n";
    cout << "  Visualisasi Graf (ASCII)\n";
    cout << "===========================\n";

    map<int, vector<pair<int, double>>> adjacencyList;

    for (const auto &edge : edges) {
        adjacencyList[edge.from].push_back({edge.to, edge.weight});
        adjacencyList[edge.to].push_back({edge.from, edge.weight});
    }

    cout << "\nNode dan Koneksinya:\n";
    for (int i = 1; i <= numNodes; ++i) {
        cout << "  Node " << i << " terhubung ke:\n";
        for (const auto &neighbor : adjacencyList[i]) {
            cout << "    -> Node " << neighbor.first << " (Biaya: " << neighbor.second << ")\n";
        }
        cout << endl;
    }

    cout << "Graf dalam bentuk ASCII:\n\n";
    for (int i = 1; i <= numNodes; i++) {
        cout << "  (" << i << ")";
        if (i < numNodes) cout << " --- ";
    }
    cout << endl;

    cout << "\nRincian Edge (Koneksi dan Biaya):\n";
    for (const auto &edge : edges) {
        cout << "  Node " << edge.from << " <-> Node " << edge.to
                  << " | Biaya: " << edge.weight << endl;
    }
}

void Graph::generateGraphvizDOT(const std::string &filename) {
    ofstream file(filename);
    if (!file) {
       cerr << "Gagal membuat file: " << filename << endl;
        return;
    }

    file << "graph G {\n";
    for (const auto &edge : edges) {
        file << "  " << edge.from << " -- " << edge.to << " [label=\"" << edge.weight << "\"];\n";
    }
    file << "}\n";

    file.close();
    cout << "File DOT berhasil dibuat: " << filename << endl;
}
