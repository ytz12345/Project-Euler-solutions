#include <bits/stdc++.h>
#include "eulerlib.h"

map<ll, bool> ok, no;
int128 ans = 0;

void dfs(ll now, int idx, ll n, ll *f) {
    if (idx > f[0]) {
        ok[now]=1;
        return;
    }
    dfs(now, idx + 1, n, f);
    while (now <= n / f[idx]) {
        now *= f[idx];
        if (n % now != 0) break;
        dfs(now, idx + 1, n, f);
    }
}

void redfs(ll now, int idx, ll n, ll *f) {
    if (idx > f[0]) {
        no[now]=1;
        return;
    }
    redfs(now, idx + 1, n, f);
    while (now <= n / f[idx]) {
        now *= f[idx];
        if (n % now != 0) break;
        redfs(now, idx + 1, n, f);
    }
}

int main() {
    ll n = (1ll << 60) - 1, f[100];
    getFac(n, f);
    dfs(1, 1, n, f);


    for (int i = 1; i < 60; i ++) {
        ll m = (1ll << i) - 1;
        getFac(m, f);
        redfs(1, 1, m, f);
    }
    
    for (auto x : ok) {
        if (x.first < 60) continue;
        if (no[x.first])  continue;
        ans += x.first + 1;
    }
    cout << ans << endl;
}