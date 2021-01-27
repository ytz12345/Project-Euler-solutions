#include "eulerlib.h"

const int N = 100 + 1;

int lim = 1e9;

int p[N], v[N], c[N];

ll ans;

void dfs(int id, ll now) {
    if (id > p[0]) {
        ans ++;
        return;
    }
    dfs(id + 1, now);
    for (int i = 1; i <= c[id]; i ++) {
        now *= p[id];
        if (now > lim) break;
        dfs(id + 1, now);
    }
}

int main() {
    get_prime(N, p, v);
    for (int i = 1; i <= p[0]; i ++) {
        ll now = 1;
        while (1) {
            now *= p[i];
            if (now > lim) break;
            c[i] ++;
        }
    }
    dfs(1, 1);
    cout << ans << endl;
    print_time();
}
// 2944730
// Time elapsed: 0.072309 s.