#include "eulerlib.h"

const int lim = 1e9;

ll calc(ll c, ll b) {
    static ll a, d;
    c = sqr(c), b = sqr(b), d = c - b, a = sqrt(d);
    if (sqr(a) == d) return a;
    if (sqr(a + 1) == d) return a + 1;
    return 0;
}

int main() {
    ll ans = 0;
    for (int i = 5, up = lim / 3, j; i <= up; i += 2) {
        j = calc(i, i / 2);     if (j != 0) ans += i * 3 - 1;
        j = calc(i, i / 2 + 1); if (j != 0) ans += i * 3 + 1;
    }
    cout << ans << endl;
    print_time();
}
// 518408346
// Time elapsed: 4.65994 s.