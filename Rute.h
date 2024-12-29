#ifndef RUTE_H
#define RUTE_H

#include <unordered_map>
using namespace std;

class Rute {
public:
    unordered_map<int, unordered_map<int, int>> jarak;
    unordered_map<int, unordered_map<int, int>> biaya;

    void tambahRute(int dari, int ke, int jarakRute, int biayaRute);
};

#endif
