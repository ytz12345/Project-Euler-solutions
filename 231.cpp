#include "eulerlib.h"

const int N = 2e7 + 1000;

int p[N], v[N];

ll ans;

ll calc(int x) {
    ll res = 0;
    for (ll i = 1, j; p[i] <= x; i ++) {
        j = p[i];
        while (j <= x) {
            res += x / j * p[i];
            j *= p[i];
        }
    }
    return res;
}

int main() {
    get_prime(N, p, v);
    ans += calc(2e7);
    ans -= calc(15e6);
    ans -= calc(5e6);
    cout << ans << endl;
    print_time();
}
// 7526965179680
// Time elapsed: 0.256212 s.