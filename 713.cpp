#include "eulerlib.h"

ll Cn2(ll n) {
    return n * (n - 1) / 2;
}

ll calc(ll n, ll m) {
    if (m >= n) return 1;
    if ((n - m) < n / 2) return n - m + 1;
    if ((n - m) == n / 2) {
        if (n & 1) return n - m + 2;
        else       return n - m + 3;
    }

    ll siz = n / (m - 1), big = n % (m - 1), sma = m - 1 - big;
    return Cn2(siz) * sma + Cn2(siz + 1) * big;
}

ll n, ans;

int main() {
    cin >> n;
    for (int i = 2; i <= n; i ++) ans += calc(n, i);
    cout << ans << endl;
    print_time();
}