#include "eulerlib.h"

const int N = 1e7 + 1;

int p[N], v[N];

int ans, fac[N], cnt[N];

int main() {
    for (int i = 1; i < N; i ++) fac[i] = 1;
    for (int i = 2, j; i < N; i ++) {
        if (v[i]) continue;
        for (j = i; 1ll * j * i < N; j *= i);
        for (; j != i; j /= i) for (int k = j; k < N; k += j) cnt[k] ++;
        for (int k = j; k < N; k += j) v[k] = 1, fac[k] *= (cnt[k] + 2), cnt[k] = 0;
    }
    for (int i = 3; i < N; i ++) ans += fac[i] == fac[i - 1];
    cout << ans << endl;
    print_time();
}
// 986262
// Time elapsed: 0.838952 s.