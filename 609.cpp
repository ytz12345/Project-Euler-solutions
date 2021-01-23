#include "eulerlib.h"

const int N = 1e8 + 1;

const int Mod = 1e9 + 7;

int n, p[N], v[N];

int to[N], cnt[20];

ll ans = 1;

int main() {
    //cin >> n;
    n = N - 1;
    get_prime(n + 1, p, v);

    for (int i = 1, c = 0; i <= n; i ++) {
        c += v[i] == 0;
        to[i] = c;
    }
    
    for (int i = 2, j, c; i <= n; i ++) {
        c = v[i], j = to[i];
        while (1) {
            c += v[j];
            cnt[c] ++;
            if (cnt[c] >= Mod) cnt[c] -= Mod;
            j = to[j];
            if (j == 0) break;
        }
    }
    for (int i = 0; i < 20; i ++) 
        if (cnt[i] != 0)
            ans = ans * cnt[i] % Mod;

    cout << ans << endl;
    print_time();
}
// 172023848
// Time elapsed: 4.73033 s.