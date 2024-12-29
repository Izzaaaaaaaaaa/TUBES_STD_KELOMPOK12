#ifndef PENJADWALAN_H
#define PENJADWALAN_H

#include <vector>
#include "Barang.h"
#include "Kendaraan.h"
#include "OptimasiMuatan.h"
using namespace std;

class Penjadwalan {
public:
    void buatJadwal(vector<Barang> &barang, vector<Kendaraan> &kendaraan, OptimasiMuatan &optimasi);
};

#endif
