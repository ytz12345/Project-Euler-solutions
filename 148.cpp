#include "eulerlib.h"

/*
// for check
int calc(int x) {
    int res = 0;
    for (int i = 7; i <= x; i *= 7) res += x / i;
    return res;
}

int count(int x) {
    int res = 0;
    for (int i = 0; i <= x; i ++) res += calc(x) - calc(i) - calc(x - i) == 0;
    return res; 
}
*/

int m = 1, n = 1e9, c = 0;

int calc(const int &i) {
    static int j, t, res;
    if (i >= m * 7) m *= 7, c ++; res = 1;
    for (t = i, j = m; j != 0; t %= j, j /= 7) res *= t / j + 1;
    return res;
}

void calc_cc(const int &i, int &cc, int &mm) {
    mm = m, cc = c;
    while (i + mm >= n) cc --, mm /= 7;
}

int main() {
    ll ans = 0, tmp; int cc, mm;
    for (int i = 0; i < n; ) {
        tmp = calc(i), calc_cc(i, cc, mm);
        for (int j = 1; j <= cc; j ++) tmp *= 28;
        ans += tmp;
        i += mm;
        if (mm == 0) break;
    }
    cout << ans << endl;
    print_time();
}
// 2129970655314432
// Time elapsed: 0.003626 s.