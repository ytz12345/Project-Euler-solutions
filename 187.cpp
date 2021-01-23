#include "eulerlib.h"

const int N = 1e8;

int p[N], v[N];

ll ans;

int main() {
    get_prime(N, p, v);

    for (int i = 1; i <= p[0] && 1ll * p[i] * p[i] < N; i ++) 
        for (int j = i; j <= p[0] && 1ll * p[i] * p[j] < N; j ++)
            ans ++;

    cout << ans << endl;
    print_time();
}
// 17427258
// Time elapsed: 1.25578 s.