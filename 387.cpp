#include <bits/stdc++.h>
#include "eulerlib.h"

typedef long long ll;

const ll lim = 1e13;

ll ans = 0;

ll isHarshad(ll x) {
    if (x == 0) return -1;
    ll y = 0;
    for (ll z = x; z != 0; y += z % 10, z /= 10);
    if (x % y == 0) {
        return x / y;
    }
    return -1;
}

void dfs(ll x) {
    if (x > lim) return;
    ll y = isHarshad(x);
    if (x != 0 && y != -1) {
        if (is_prime(y)) {
            printf("%lld\n", x);
            for (ll i = 0; i < 10; i ++) 
                if (is_prime(x * 10 + i))
                    ans += x * 10 + i;
        }
    } 
    else if (x != 0) {
        return;
    }
    for (ll i = 0; i < 10; i ++) {
        if (x == 0 && i == 0) continue;
        dfs(x * 10 + i);
    }
}

int main() {
    dfs(0);
    printf("%lld\n", ans);
}
