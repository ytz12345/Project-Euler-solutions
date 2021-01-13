#include "eulerlib.h"

const int N = 1e8 + 1;

int p[N], v[N], u[N];

vector <piir> e[6000000];

ll ans;

void dfs(int x, int y, int z, int last, int id) {
    if (z >= N) return;
    if (x < y && y != last && u[y] && u[z]) {
        ans += x + y + z - 3;
        //cout << x - 1 << ' ' << y - 1 << ' ' << z - 1 << endl;
    }
    if (id > p[0]) return;
    last = y;
    int limit = (N - 1) / p[id] / p[id];
    if (z <= limit) {
        dfs(x, y, z, last, id + 1);
        while (z <= limit) {
            y *= p[id];
            z = z * p[id] * p[id];
            dfs(x, y, z, last, id + 1);
        }
    } 
}

int main() {
    get_prime(N, p, v);
    // cout << p[0] << endl;
    // 5761455
    // print_time();
    // Time elapsed: 1.08537 s.
    for (int i = 1; i <= p[0]; i ++) u[p[i] + 1] = i;
    for (int i = 1; i <= p[0]; i ++) {
        for (int j = p[i]; j < N; j += p[i]) {
            if (u[j]) {
                int x = j, y = 0;
                while (x % p[i] == 0) x /= p[i], y ++;
                e[u[j]].push_back(piir(p[i], y));
            }
        }
    }
    // print_time();
    // Time elapsed: 14.3531 s.

    for (int i = 1; i <= p[0]; i ++) {
        if (i % 100000 == 0) cout << i << endl;
        ll x = p[i] + 1, y = 1, z = 1;
        for (int j = 0; j < e[i].size(); j ++) {
            int k = (e[i][j].second + 1) / 2;
            for (; k > 0; k --) y *= e[i][j].first;
        }
        z = y * y / x;
        if (z >= N) continue;
        dfs(x, y, z, 0, 1);
    }

    cout << ans << endl;
    // 100315739184392
    print_time();
    // Time elapsed: 23.3817 s.
    return 0;
}