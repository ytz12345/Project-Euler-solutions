#include "eulerlib.h"

const int N = 5e7;

int cnt[N + 1];

int ans;

int main() {
    int i, l, r, d; ll k;
    for (i = 4, d = 1; i <= N; i += 4, d ++) { // 4d
        for (l = d + 1; l < i && (k = 1ll * l * (i - l)) <= N; l ++) cnt[k] ++;
        for (r = i - 1; r > l && (k = 1ll * r * (i - r)) <= N; r --) cnt[k] ++;
    }
    for (int i = 1; i <= N; i ++) ans += cnt[i] == 1;
    cout << ans << endl;
    print_time();
}
// 2544559
// Time elapsed: 2.22786 s.