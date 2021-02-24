#include "eulerlib.h"

ll ans = 0;

vector<int> arr, used;

void dfs(int now, int m, int last) {
    if (now == m) {
        int i, ok = 1, tmp = last;
        for (i = 2; i < m; i <<= 1) {
            used[last = (last << 1 | 0) & (m - 1)] ++;
            if (used[last] > 1) ok = 0;
        }
        if (ok) {
            ll x = 0;
            for (i = 0; i < m; i ++) x = (x << 1) | arr[i];
            ans += x;
        }

        for (last = tmp, i = 2; i < m; i <<= 1) used[last = (last << 1 | 0) & (m - 1)] --;

        return;
    }

    arr[now] = 0;
    if (!used[(last << 1 | arr[now]) & (m - 1)]) {
        used[(last << 1 | arr[now]) & (m - 1)] ++;
        dfs(now + 1, m, (last << 1 | arr[now]) & (m - 1));
        used[(last << 1 | arr[now]) & (m - 1)] --;
    }
    arr[now] = 1;
    if (!used[(last << 1 | arr[now]) & (m - 1)]) {
        used[(last << 1 | arr[now]) & (m - 1)] ++;
        dfs(now + 1, m, (last << 1 | arr[now]) & (m - 1));
        used[(last << 1 | arr[now]) & (m - 1)] --;
    }
}

int main() {
    int n = 5; cin >> n;

    int m = 1 << n;
    arr.resize(m), used.resize(m);
    for (int i = 0; i < n; i ++) arr[i] = 0;
    used[0] = 1, dfs(n, m, 0);

    cout << ans << endl;
    print_time();
}
// 209110240768
// Time elapsed: 0.009084 s.