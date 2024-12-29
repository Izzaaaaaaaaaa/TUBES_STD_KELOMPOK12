#include <iostream>
#include <vector>
#include "Barang.h"
#include "Kendaraan.h"
#include "Rute.h"
#include "OptimasiMuatan.h"
#include "OptimasiRute.h"
#include "Penjadwalan.h"
#include "OptimasiMuatan.cpp"
#include "OptimasiRute.cpp"
#include "Penjadwalan.cpp"
#include "Rute.cpp"

using namespace std;

int main() {
    // Data barang
    vector<Barang> barang = {
        {1, 10, 5, 2},
        {2, 20, 15, 1},
        {3, 15, 10, 3}
    };

    // Data kendaraan
    vector<Kendaraan> kendaraan = {
        {1, 50, 50, 100},
        {2, 40, 40, 90}
    };

    // Data rute
    Rute rute;
    rute.tambahRute(1, 2, 10, 50);
    rute.tambahRute(1, 3, 15, 70);
    rute.tambahRute(2, 3, 5, 30);
    rute.tambahRute(2, 4, 20, 100);
    rute.tambahRute(3, 4, 25, 80); // Tambahan rute
    rute.tambahRute(4, 1, 30, 120); // Tambahan rute

    // Validasi apakah semua node terhubung
    int jumlahNode = 4;
    for (int i = 1; i <= jumlahNode; i++) {
        for (int j = 1; j <= jumlahNode; j++) {
            if (i != j && rute.biaya[i][j] == 0) {
                std::cerr << "Error: Node " << i << " dan " << j << " tidak terhubung.\n";
            }
        }
    }

    // Optimasi rute menggunakan Traveling Salesman Problem
    OptimasiRute optRute;
    auto [ruteOptimal, biayaMinimal] = optRute.travelingSalesman(rute, 1, jumlahNode);
    if (biayaMinimal == INT_MAX) {
        cout << "Tidak ada rute yang valid.\n";
    } else {
        cout << "Rute Optimal: ";
        for (int node : ruteOptimal) {
        cout << node << " ";
        }
        cout << "\nBiaya Minimal: " << biayaMinimal << std::endl;
    }

    // Optimasi muatan dan penjadwalan
    OptimasiMuatan optMuatan;
    Penjadwalan penjadwalan;
    penjadwalan.buatJadwal(barang, kendaraan, optMuatan);

    return 0;
}