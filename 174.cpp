#include "eulerlib.h"

ll cnt[1001000], c[1001000];

int main() {
    ll n = 1e6, tmp, ans = 0;
    ll l, r, mid = n / 4 - 1;
    for (ll i = n / 4 + 1; i >= 3; i --) {
        l = (i & 1) ? 1 : 2, r = min(mid, i - 2);
        while (l <= r) {
            mid = l + r >> 1;
            if (i * i - mid * mid <= n) r = mid - 1;
            else l = mid + 1;
        }
        while (mid >= 2 && i * i - (mid - 1) * (mid - 1) <= n) mid --;
        while (i * i - mid * mid > n) mid ++;

        if (mid > i) continue;
        for (ll j = i - 2; j >= mid; j -= 2) 
            cnt[i * i - j * j] ++;
    }
    for (int i = 1; i <= n; i ++) c[cnt[i]] ++;
    for (int i = 1; i <= 10; i ++) ans += c[i];
    cout << ans << endl;
    print_time();
}
// 209566
// Time elapsed: 0.050984 s.