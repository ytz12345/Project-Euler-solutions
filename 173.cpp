#include "eulerlib.h"

int main() {
    ll n = 1e6, ans = 0;
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
        ans += (i - mid) / 2;
        //cout << i << ' ' << mid << ' ' << (i - mid) / 2 << endl;
    }
    cout << ans << endl;
    print_time();
}
// 1572729
// Time elapsed: 0.020915 s.