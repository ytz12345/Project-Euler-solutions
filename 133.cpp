#include "eulerlib.h"

const int N = 1e5;

int p[N], v[N], ans;

int main() {
    get_prime(N, p, v);
    for (int i = 1; i <= p[0]; i ++) {
        int l = get_repunit(p[i]);
        if (l == 0) {
            ans += p[i];
            continue;
        }
        while (l % 2 == 0) l /= 2;
        while (l % 5 == 0) l /= 5;
        if (l != 1) ans += p[i];
    }
    cout << ans << endl;
    print_time();
}
// 453647705
// Time elapsed: 5.43708 s.