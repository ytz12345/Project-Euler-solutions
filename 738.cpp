#include "eulerlib.h"

const ll  Lim = 1e10;
const int Mod = 1e9 + 7;

vector <ll> pw[35];

inline ll dfs(const int &remain, const ll &min_val, const ll &lim) {
    ll ret = 0;
    
    if (remain == 1) ret = (lim - min_val + 1) % Mod;
    else {
        int max_val = upper_bound(pw[remain].begin(), pw[remain].end(), lim) - pw[remain].begin() - 1;
        for (int i = min_val; i <= max_val; i ++) {
            ret += dfs(remain - 1, i, lim / i);
            if (ret >= Mod) ret -= Mod;
        }
    }

    return ret;
}

int main() {
    // init
    for (int i = 2; i < 35; i ++) {
        pw[i].pb(0);
        for (int j = 1; ; j ++) {
            ll t = 1;
            for (int k = 0; k < i; k ++) {
                t *= j;
                if (t > Lim) break;
            }
            if (t <= Lim) pw[i].pb(t);
            else {
                pw[i].pb(1e18);
                break;
            }
        }
    }

    ll n = 1e10, ans = 0;

    //cin >> n; 
    int m = n % Mod + Mod;
    for (int i = 1; ; i ++, m --) {
        if ((1ll << i) > n) break;
        ans += dfs(i, 2, n) * m % Mod;
        if (ans >= Mod) ans -= Mod;
    }

    cout << (ans + n) % Mod << endl;
    print_time();
}
// 143091030
// Time elapsed: 37.6131 s.