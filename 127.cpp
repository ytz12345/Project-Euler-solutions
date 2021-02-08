#include "eulerlib.h"

const int N = 120001;

int p[N], v[N], rad[N];

vector <int> d[N];

ll ans;

bool check(int x, int y) {
    for (int i = 0, j = 0; i < d[x].size(); i ++) {
        while (j < d[y].size() && d[y][j] < d[x][i]) j ++;
        if (j < d[y].size()) {
            if (d[y][j] == d[x][i]) return 0;
        } else {
            break;
        }
    }
    return 1;
}

int main() {
    for (int i = 1; i < N; i ++) rad[i] = 1;
    for (int i = 2; i < N; i ++) {
        if (v[i]) continue;
        p[++ p[0]] = i;
        for (int j = i; j < N; j += i) {
            d[j].pb(i); 
            rad[j] *= i;
            v[j] = 1;
        }
    }

    for (int i = 1; i < N; i ++) {
        //cout << i << ' ' << rad[i] << endl;
        for (int j = i + 1, up = N - 1 - i; j <= up; j ++) {
            if (1ll * rad[i] * rad[j] < N && check(i, j)) {
                int z = i + j;
                if (1ll * rad[i] * rad[j] * rad[z] < z) ans += z;//, cout << i << ' ' << j << ' ' << z << endl;
            }
        }
    }
    cout << ans << endl;
    print_time();
}
// 18407904
// Time elapsed: 8.53276 s.