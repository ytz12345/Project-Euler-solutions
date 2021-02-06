#include "eulerlib.h"

const int N = 1e6 + 100;

int p[N], v[N];

ll ans, m[3], a[3];

int now, c[] = {10, 100, 1000, 10000, 100000, 1000000};

int main() {
    get_prime(N, p, v);
    
    for (int i = 3; p[i] <= 1e6; i ++) {
        if (p[i] > c[now]) now ++;
        m[1] = c[now], a[1] = p[i];
        m[2] = p[i + 1], a[2] = 0;
        ans += crt(m, a, 2);
    }

    cout << ans << endl;
    print_time();
}

// 18613426663617118
// Time elapsed: 0.024047 s.