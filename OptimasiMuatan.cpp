#include "OptimasiMuatan.h"

using namespace std;

vector<Barang> OptimasiMuatan::optimalkanMuatan(vector<Barang> barang, int kapasitasBerat, int kapasitasVolume) {
    int n = barang.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(kapasitasBerat + 1, vector<int>(kapasitasVolume + 1, 0)));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= kapasitasBerat; w++) {
            for (int v = 0; v <= kapasitasVolume; v++) {
                if (barang[i - 1].berat <= w && barang[i - 1].volume <= v) {
                    dp[i][w][v] = max(dp[i - 1][w][v], dp[i - 1][w - barang[i - 1].berat][v - barang[i - 1].volume] + 1);
                } else {
                    dp[i][w][v] = dp[i - 1][w][v];
                }
            }
        }
    }

    vector<Barang> hasil;
    int w = kapasitasBerat, v = kapasitasVolume;
    for (int i = n; i > 0; i--) {
        if (dp[i][w][v] != dp[i - 1][w][v]) {
            hasil.push_back(barang[i - 1]);
            w -= barang[i - 1].berat;
            v -= barang[i - 1].volume;
        }
    }

    return hasil;
}