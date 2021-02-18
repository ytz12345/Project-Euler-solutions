#include "eulerlib.h"

const int N = 1e8 + 1;

const int Mod = 1e9 + 7;

int fac[N], inv[N], ans;

int main() {
    get_inv(N - 1, fac, inv, Mod);

    ll n = 9, k = 1, m = n / k;
    int pow2_2m = qpow(qpow(2, m * 2, Mod), Mod - 2, Mod);
    int tmp = qpow(2, n, Mod);
    for (int t = 0, up = k / 2; t <= up; t ++) {
        ans += 1ll * tmp * fac[k] % Mod * inv[t] % Mod * inv[t] % Mod * inv[k - t - t] % Mod;
        tmp = 1ll * tmp * pow2_2m % Mod;
        if (ans >= Mod) ans -= Mod;
    }
    cout << ans << endl;
    print_time();
    return 0;
}
// 259158998
// Time elapsed: 4.83447 s.