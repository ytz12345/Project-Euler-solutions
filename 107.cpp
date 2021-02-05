#include "eulerlib.h"

struct edge {
    int u, v, w;
}e[2000];

int n = 40, m, ans;

int f[50];

int fa(int x) {return x == f[x] ? x : f[x] = fa(f[x]);}

int main() {
    int x;
    for (int i = 1; i <= n; i ++) {
        f[i] = i;
        for (int j = 1; j <= i; j ++) cin >> x;
        for (int j = i + 1; j <= n; j ++) {
            cin >> x;
            if (x != 0) e[++ m] = (edge){i, j, x}, ans += x;
        }

    }
    sort (e + 1, e + m + 1, [&](edge a, edge b) {
        return a.w < b.w;
    });

    for (int i = 1, j = 1; j < n; i ++) {
        int x = fa(e[i].u), y = fa(e[i].v);
        if (x == y) continue;
        f[y] = x; ans -= e[i].w; j ++;
    }
    cout << ans << endl;
    print_time();
}
// 259679
// Time elapsed: 0.007435 s.