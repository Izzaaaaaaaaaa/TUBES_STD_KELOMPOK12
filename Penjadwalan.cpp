#include "Penjadwalan.h"
#include <algorithm>
#include <iostream>

using namespace std;

void Penjadwalan::buatJadwal(vector<Barang> &barang, vector<Kendaraan> &kendaraan, OptimasiMuatan &optimasi) {
    sort(barang.begin(), barang.end(), [](Barang &a, Barang &b) {
        return a.prioritas < b.prioritas;
    });

    for (auto &k : kendaraan) {
        vector<Barang> muatan = optimasi.optimalkanMuatan(barang, k.kapasitas_berat, k.kapasitas_volume);
        if (!muatan.empty()) {
            cout << "Kendaraan " << k.id << " membawa barang: ";
            for (auto &b : muatan) {
                cout << b.id << " ";
            }
            cout << endl;

            for (auto &m : muatan) {
                barang.erase(remove_if(barang.begin(), barang.end(), [&](Barang &br) { return br.id == m.id; }), barang.end());
            }
        }
    }
}
