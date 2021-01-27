#include "eulerlib.h"

const int N = 1e6 + 1;

int p[N], v[N];

int main() {
    get_prime(N, p, v);
    for (int i = 7037; ; i += 2) 
        if (2ll * i * p[i] % (1ll * p[i] * p[i]) > 1e10) {
            cout << i << endl;
            print_time();
            return 0;
        }
}
// 21035
// Time elapsed: 0.017902 s.