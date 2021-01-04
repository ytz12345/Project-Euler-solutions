#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e6 + 1;

ll ans;

bool dfs(ll remain, ll x, ll dep, ll y) {
    if (dep == 0) {
        return remain == 0 && y == 0;
    }

    y = y * 10 + x % 10;
    if (dfs(remain - y, x / 10, dep - 1, 0)) {
        printf("%lld ", y);
        return true;
    } 
    return dfs(remain, x / 10, dep - 1, y);
}

int cnt;

ll rev(ll x) {
    static char str[20];
    cnt = 0;
    while (x != 0) str[cnt ++] = x % 10, x /= 10;
    for (int i = 0; i < cnt; i ++)
        x = x * 10 + str[i];
    return x;
}

int main() {
    // printf("%lld\n", rev(12345));
    for (int i = 2; i < N; i ++) {
        if (dfs(i, rev(1ll * i * i), cnt, 0))
            ans += 1ll * i * i, printf("\n%d\n", i);
    }
    printf("%lld\n", ans);
}