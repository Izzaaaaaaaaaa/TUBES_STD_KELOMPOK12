#include "Rute.h"

using namespace std;

void Rute::tambahRute(int dari, int ke, int jarakRute, int biayaRute) {
    jarak[dari][ke] = jarakRute;
    jarak[ke][dari] = jarakRute;
    biaya[dari][ke] = biayaRute;
    biaya[ke][dari] = biayaRute;
}
