#include "eulerlib.h"

const int N = 4e7 + 1;

int phi[N], p[N], v[N], d[N];

ll ans;

int main() {
    get_phi(N, phi, p, v);
    d[1] = 1;
    for (int i = 2; i < N; i ++) {
        d[i] = d[phi[i]] + 1;
        if (d[i] == 25) ans += i * (1 - v[i]);
    }
    cout << ans << endl;
    print_time();
}
// 1677366278943
// Time elapsed: 1.10777 s.