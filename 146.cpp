#include "eulerlib.h"

bool check(ll x) {
    if (!is_prime(x + 1)) return 0;
    if (!is_prime(x + 3)) return 0;
    if (!is_prime(x + 7)) return 0;
    if (!is_prime(x + 9)) return 0;
    if (!is_prime(x + 13)) return 0;
    if (!is_prime(x + 27)) return 0;

    if (is_prime(x + 11)) return 0;
    if (is_prime(x + 17)) return 0;
    if (is_prime(x + 19)) return 0;
    if (is_prime(x + 21)) return 0;
    if (is_prime(x + 23)) return 0;

    return 1;
}

ll ans;

int main() {
    for (int i = 10; i <= 15e7; i += 30) {
        if (check(sqr(i))) 
            ans += i, cout << i << endl;
        if (check(sqr(i + 10)))
            ans += i + 10, cout << i + 10 << endl;
    }
    cout << ans << endl;
    print_time();
}
// 10
// 315410
// 927070
// 2525870
// 8146100
// 16755190
// 39313460
// 97387280
// 119571820
// 121288430
// 130116970
// 139985660

// 676333270