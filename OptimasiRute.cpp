#include "OptimasiRute.h"
#include <iostream> // Untuk logging

std::pair<std::vector<int>, int> OptimasiRute::travelingSalesman(Rute &rute, int start, int jumlahNode) {
    std::vector<int> nodes;
    for (int i = 1; i <= jumlahNode; i++) {
        if (i != start) nodes.push_back(i);
    }

    std::vector<int> bestPath;
    int minCost = INT_MAX;

    do {
        int currentCost = 0, currentNode = start;
        std::vector<int> currentPath = {start};

        for (int nextNode : nodes) {
            if (rute.biaya[currentNode][nextNode] == 0) {
                currentCost = INT_MAX;
                break;
            }
            currentCost += rute.biaya[currentNode][nextNode];
            currentPath.push_back(nextNode);
            currentNode = nextNode;
        }

        if (currentCost != INT_MAX && rute.biaya[currentNode][start] != 0) {
            currentCost += rute.biaya[currentNode][start];
            currentPath.push_back(start);

            // Logging setiap iterasi
            std::cout << "Cek rute: ";
            for (int node : currentPath) {
                std::cout << node << " ";
            }
            std::cout << " dengan biaya: " << currentCost << std::endl;

            if (currentCost < minCost) {
                minCost = currentCost;
                bestPath = currentPath;
            }
        }
    } while (std::next_permutation(nodes.begin(), nodes.end()));

    return {bestPath, minCost};
}