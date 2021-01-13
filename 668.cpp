#include "eulerlib.h"

const int N = 1e5;
const ll NN = 1e10;

int p[N + 1], v[N + 1];

ll dp[2][3000000];

ll ans, max_siz;

int main() {
    get_prime(N + 1, p, v);
    dp[1][0] = 0;
    for (ll i = 1; i <= NN; i *= 2) dp[1][++ dp[1][0]] = i;
    ans += dp[1][0] - 3 + 1;

    for (ll x, j, l, r, now, lim, i = 2; i <= p[0]; i ++) {
        now = i & 1;
        dp[now][0] = 0;
        r = NN / p[i];
        lim = r / p[i];
        l = p[i] + 1;
        for (j = 1; j <= dp[!now][0]; j ++) {
            x = dp[!now][j];
            if (x > r) continue;
            while (1) {
                dp[now][++dp[now][0]] = x;
                if (x >= l) ans ++;
                if (x > lim) break;
                x *= p[i];
            }
        }
    }
    
    cout << ans << endl;
    print_time();
}
// 2811077773
// Time elapsed: 16.8134 s.