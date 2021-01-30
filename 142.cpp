#include "eulerlib.h"

const int N = 1e3 + 1;

int main() {
    ll i, j, k, z, s1, s2, s3, ans = 1e9;

    for (i = 1; i < N; i ++)
        for (j = 1; j < N; j ++) {
            k = i * i + j * j;
            if (!is_sqr(k)) continue;
            // x - y = i * i
            // y - z = j * j
            // x - z = i * i + j * j
            for (z = 1; z < N * N; z ++) { // guess the limit
                // s1 = y + z = z + z + j * j
                s1 = z + z + j * j;
                if (!is_sqr(s1)) continue;
                // s2 = x + z = z + z + j * j + i * i
                s2 = z + z + k;
                if (!is_sqr(s2)) continue;
                // s3 = x + y = z + z + j * j + i * i + j * j
                s3 = z + z + k + j * j;
                if (!is_sqr(s3)) continue;
                //cout << z << ' ' << z + j * j << ' ' << z + k << endl;
                ans = min(ans, z + z + j * j + z + j * j + i * i);
            }
        }
    cout << ans << endl;
    print_time();
}
// 1006193
// Time elapsed: 22.8494 s.