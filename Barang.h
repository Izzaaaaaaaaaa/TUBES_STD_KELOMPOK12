#ifndef BARANG_H
#define BARANG_H

using namespace std;

class Barang {
public:
    int id, berat, volume, prioritas;

    Barang(int id, int berat, int volume, int prioritas)
        : id(id), berat(berat), volume(volume), prioritas(prioritas) {}
};

#endif