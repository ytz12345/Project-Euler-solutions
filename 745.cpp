#include "eulerlib.h"

const int N = 1e7 + 1;
const int Mod = 1e9 + 7;
const int ES = 6079291;

int u[N], v[N], p[N];

vector <piir> e;

inline ll sqr_t(const ll &x) {
    static ll z; z = sqrt(x);
    while (sqr(z + 1) <= x) z ++; while (sqr(z) > x) z --;
    return z;
}

inline ll solve(const ll &n) {
    ll i, j, p, q, cnt, ans = 0, t = sqr_t(n);
    for (i = 1; i <= t; i ++) {
        p = n / (i * i), cnt = 0;
        for (j = 0; j < ES && (q = sqr(ll(e[j].first))) <= p; j ++) 
            cnt = (cnt + p / q * e[j].second) % Mod;
        ans = (ans + i * i % Mod * cnt) % Mod;
    }
    return ans;
}

int main() {
    get_u(N, p, v, u); 
    e.resize(ES); int c = 0;
    for (int i = 1; i < N; i ++)
        if (u[i] != 0)
            e[c ++] = pr(i, u[i]);

    cout << solve(1e14) << endl;
    print_time();
}
// 94586478
// Time elapsed: 2.77587 s.