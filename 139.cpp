#include "eulerlib.h"

int main() {
    ll ans = 0, lim = 1e8;
    ll i, j, z;
    for (i = 3; i < lim; i ++)  {
        z = sqr(i) + sqr(i + 1);
        if ((j = is_sqr(z)) != 0) 
            ans += lim / (i + i + 1 + j);
    }
    cout << ans << endl;
    print_time();
}
// 10057761