#include "eulerlib.h"

const int N = 5e4 + 1;

int lim = 25;

int p[N], v[N];

int ans, cnt;

int main() {
    get_prime(N, p, v);
    for (int i = 4; i < N; i ++) {
        if (!v[i]) continue;
        int l = get_repunit(i);
        if (l != 0 && (i - 1) % l == 0) {
            cnt ++;
            ans += i;
            cout << cnt << ' ' << i << ' ' << ans << endl;
            if (cnt >= lim) break;
        }
    }
    print_time();
}
// 25 14701 149253
// Time elapsed: 0.153042 s.