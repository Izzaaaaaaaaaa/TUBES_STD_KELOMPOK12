#ifndef KENDARAAN_H
#define KENDARAAN_H

using namespace std;

class Kendaraan {
public:
    int id, kapasitas_berat, kapasitas_volume, biaya_operasional;

    Kendaraan(int id, int kapasitas_berat, int kapasitas_volume, int biaya_operasional)
        : id(id), kapasitas_berat(kapasitas_berat), kapasitas_volume(kapasitas_volume), biaya_operasional(biaya_operasional) {}
};

#endif