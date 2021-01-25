#include "eulerlib.h"

ll n, f[60][60];

vector <ll> a;

int128 ans;

int check(ll x) {
    for (int i = 2; i < n; i ++)
        if (x % sqr(i) == 0)
            return 0;
    return 1;
}

int main() {
    n = 51;
    for (int i = 0; i < 60; i ++) f[i][0] = 1;
    for (int i = 1; i < 60; i ++)
        for (int j = 1; j <= i; j ++)
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j <= i; j ++)
            a.push_back(f[i][j]);
    sort (a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    for (ll x : a) ans += x * check(x);
    cout << ans << endl;
    print_time();
}
// 34029210557338
// Time elapsed: 0.004162 s.