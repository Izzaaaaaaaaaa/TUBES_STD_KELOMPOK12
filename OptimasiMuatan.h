#ifndef OPTIMASIMUATAN_H
#define OPTIMASIMUATAN_H

#include <vector>
#include "Barang.h"
using namespace std;

class OptimasiMuatan {
public:
    vector<Barang> optimalkanMuatan(vector<Barang> barang, int kapasitasBerat, int kapasitasVolume);
};

#endif